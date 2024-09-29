#!/usr/bin/python3
import roboticstoolbox as rtb
import numpy as np
from sensor_msgs.msg import JointState
from spatialmath import SE3
from math import pi
from math import radians
import rclpy
from rclpy.node import Node
from scipy.optimize import minimize
from geometry_msgs.msg import PoseStamped
from fun4_interfaces.srv import RunAuto,ChangeMode
# from tf_transformations import euler_from_quaternion

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
        self.target_joint_positions = [0.0, 0.0, 0.0]
        self.xe, self.ye, self.ze = 0.0, 0.0, 0.0  # Initialize end-effector position
        self.tolerance = 0.01  # Tolerance 
        self.flag = True

        self.pid_controllers = [PIDController(1.5),  # For joint 1
                                PIDController(1.5),  # For joint 2
                                PIDController(1.5)]  # For joint 3
        
    def joint_state_callback(self, msg: JointState):
        if len(msg.position) >= 3:
            self.current_joint_positions = list(msg.position[:3])  # Update the current positions
        
    def callback_end_pose(self, msg:PoseStamped):
        self.xe = msg.pose.position.x
        self.ye = msg.pose.position.y
        self.ze = msg.pose.position.z

    def callback_user(self,request:ChangeMode.Request, response:ChangeMode.Response): # รับ
        self.mode = request.mode
        return response

    def callback_target(self,request:RunAuto.Request, response:RunAuto.Response): # รับ
        xt = request.target.x
        yt = request.target.y
        zt = request.target.z

        # if self.mode == 3:
        #     self.get_logger().info(f'Random target x = {xt}, y = {yt}, z = {zt}')
        #     self.get_logger().info(f'Current position end-effector x = {self.xe}, y = {self.ye}, z = {self.ze}')

        q_target = self.inverse_kinematic(xt, yt, zt, self.mode)
        self.update_joint_states(q_target)

        self.finish = self.check_if_reached(xt,yt,zt)
        
        response.reach_target = self.finish
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
        distance = np.sqrt((xt - self.xe) ** 2 +
                           (yt - self.ye) ** 2 +
                           (zt - self.ze) ** 2)
        if distance <= self.tolerance:
            finish = True
            # if self.mode == 3:
            # self.get_logger().info(f'Target reached.')
        else:
            finish = False
            # if self.mode == 3:
            # self.get_logger().info(f'Target not reached yet.')
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