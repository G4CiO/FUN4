#!/usr/bin/python3
import roboticstoolbox as rtb
import numpy as np
from sensor_msgs.msg import JointState
from spatialmath import SE3
from math import pi
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from fun4_interfaces.srv import RunAuto,ChangeMode

class PIDController:
    def __init__(self, kp):
        self.kp = kp
        self.prev_error = 0

    def compute(self, setpoint, current_value):
        error = setpoint - current_value
        output = self.kp * error
        return output

class Auto(Node):

    def __init__(self):
        super().__init__('auto')
        self.get_logger().info('Auto node has started')
        # Pub
        self.joint_state_pub = self.create_publisher(JointState, '/joint_states', 10)
        # Sub
        self.end_pose_sub = self.create_subscription(PoseStamped, '/end_effector', self.callback_end_pose, 10)
        self.joint_state_sub = self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 10)
        # timer
        self.dt = 0.01
        self.timer = self.create_timer(self.dt, self.timer_call)
        # Service Server (รับ mode เข้ามา)
        self.take_target = self.create_service(RunAuto, '/target_', self.callback_target)
        self.take_mode = self.create_service(ChangeMode, '/mode_pose', self.callback_user)

        # Innitial
        self.mode = 0
        self.finish = True
        self.r_min = 0.03
        self.r_max = 0.535
        self.current_joint_positions = [0.0, 0.0, 0.0]
        self.xe, self.ye, self.ze = 0.0, 0.0, 0.0  # Initialize end-effector position
        self.tolerance = 0.001  # Tolerance 
        self.flag = True
        self.q_sol = []

        self.pid_controllers = [PIDController(3.0),  # For joint 1
                                PIDController(3.0),  # For joint 2
                                PIDController(3.0)]  # For joint 3
        
    def joint_state_callback(self, msg: JointState):
        if len(msg.position) >= 3:
            self.current_joint_positions = list(msg.position[:3])  # Update the current positions
        
    def callback_end_pose(self, msg:PoseStamped):
        self.xe = msg.pose.position.x
        self.ye = msg.pose.position.y
        self.ze = msg.pose.position.z

    def callback_user(self,request:ChangeMode.Request, response:ChangeMode.Response): # รับ
        self.mode = request.mode
        teleop_mode = request.teleop_mode

        x = request.pose.x
        y = request.pose.y
        z = request.pose.z
    
        if self.mode == 1:
            r_min = 0.03
            r_max = 0.535
            distance_squared = x**2 + y**2 + (z-0.2)**2
            if r_min**2 <= distance_squared <= r_max**2:
                response.config_check_mode1 = True

            robot = rtb.DHRobot(
                [
                    rtb.RevoluteMDH(alpha = 0.0,a = 0.0,d = 0.2,offset = 0.0),
                    rtb.RevoluteMDH(alpha = pi/2,a = 0.0,d = 0.12,offset = pi/2),
                    rtb.RevoluteMDH(alpha = 0,a = 0.25,d = -0.1,offset = pi/2),

                ],tool = SE3.Tx(0.28),
                name = "RRR_Robot"
            )

            # Desired end effector pose
            T_Position = SE3(x, y, z)
            q_sol_ik_LM, *_ = robot.ikine_LM(T_Position,mask=[1,1,1,0,0,0],q0=[0,0,0])
            response.config_mode1 = [q_sol_ik_LM[0], q_sol_ik_LM[1], q_sol_ik_LM[2]]
            response.change_mode_success = True

        if self.mode == 2:
            if teleop_mode  == 1 or teleop_mode == 2:
                response.change_teleop_mode_success = True
            response.change_mode_success = True
            response.config_mode1 = []
        if self.mode == 3:
            self.get_logger().info(f'Change to mode {self.mode} Auto ')
            response.change_mode_success = True
            response.config_mode1 = []
        return response

    def callback_target(self,request:RunAuto.Request, response:RunAuto.Response): # รับ
        if self.mode == 3:
            if self.flag:
                response.reach_target = True
            else:    
                xt = request.target.x
                yt = request.target.y
                zt = request.target.z

                q_target = self.inverse_kinematic(xt, yt, zt, self.mode)
                self.update_joint_states(q_target)
                
                self.finish = self.check_if_reached(xt,yt,zt)

                response.reach_target = self.finish
                # self.get_logger().info(f'finish in auto: {response.reach_target}')
            self.flag = False
        return response

    def inverse_kinematic(self, x, y, z, mode):
        distance_squared = x**2 + y**2 + (z-0.2)**2
        if mode == 3 and self.r_min**2 <= distance_squared <= self.r_max**2:
            # self.get_logger().info(f'Target x = {x},Target y = {y},Target z = {z}')
            robot = rtb.DHRobot(
                [
                    rtb.RevoluteMDH(alpha = 0.0,a = 0.0,d = 0.2,offset = 0.0),
                    rtb.RevoluteMDH(alpha = pi/2,a = 0.0,d = 0.12,offset = pi/2),
                    rtb.RevoluteMDH(alpha = 0,a = 0.25,d = -0.1,offset = pi/2),

                ],tool = SE3.Tx(0.28),
                name = "RRR_Robot"
            )

            # Desired end effector pose
            T_Position = SE3(x, y, z)
            q_sol_ik_LM, *_ = robot.ikine_LM(T_Position,mask=[1,1,1,0,0,0],q0=[0,0,0])
            target_joint_positions = [q_sol_ik_LM[0], q_sol_ik_LM[1], q_sol_ik_LM[2]]
            return target_joint_positions
        else:
            return None
        
    def update_joint_states(self,q_target):
        if self.mode != 3:
            return 
        if q_target is None:
            self.get_logger().warn("Invalid target joint positions. Aborting update.")
            return
        # PID
        smoothed_positions = []
        for i in range(3):
            current_pos = self.current_joint_positions[i]
            target_pos = q_target[i]
            smoothed_pos = self.pid_controllers[i].compute(target_pos, current_pos)
            new_position = current_pos + smoothed_pos * self.dt
            smoothed_positions.append(new_position)

        # Update positions
        self.current_joint_positions = smoothed_positions

        self.joint_msg = JointState()
        self.joint_msg.name = ['joint_1', 'joint_2', 'joint_3']
        self.joint_msg.header.stamp = self.get_clock().now().to_msg()
        self.joint_msg.position = smoothed_positions

        self.joint_state_pub.publish(self.joint_msg)
    
    def check_if_reached(self,xt,yt,zt):
        c1 = xt - self.xe
        c2 = yt - self.ye
        c3 = zt - self.ze
        
        # if distance <= self.tolerance:
        if c1<=self.tolerance and c2<=self.tolerance and c3<=self.tolerance:
            finish = True
        else:
            finish = False
        return finish

    def timer_call(self):
        pass
        
    


def main(args=None):
    rclpy.init(args=args)
    node = Auto()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()