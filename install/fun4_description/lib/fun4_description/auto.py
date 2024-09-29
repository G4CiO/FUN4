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
        self.timer = self.create_timer(self.dt, self.update_joint_states)
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
        self.xt, self.yt, self.zt = 0.0, 0.0, 0.0  # Initialize target position
        self.tolerance = 0.01  # Tolerance 

        self.pid_controllers = [PIDController(1.0),  # For joint 1
                                PIDController(1.0),  # For joint 2
                                PIDController(1.0)]  # For joint 3
        
    def joint_state_callback(self, msg: JointState):
        if len(msg.position) >= 3:
            self.current_joint_positions = list(msg.position[:3])  # Update the current positions
        
    def callback_end_pose(self, msg:PoseStamped):
        self.xe = msg.pose.position.x
        self.ye = msg.pose.position.y
        self.ze = msg.pose.position.z

        self.inverse_kinematic(self.xt, self.yt, self.zt, self.mode)
        # Check if the end-effector is close to the target position
        self.check_target_reached()
        self.check_if_reached()
        

    def callback_user(self,request:ChangeMode.Request, response:ChangeMode.Response): # รับ
        self.mode = request.mode
        # self.inverse_kinematic(self.x, self.y, self.z, self.mode)
        return response

    def callback_target(self,request:RunAuto.Request, response:RunAuto.Response): # รับ
        self.xt = request.target.x
        self.yt = request.target.y
        self.zt = request.target.z
        self.get_logger().info(f'Take Target. Current finish status = {self.finish}')

        # self.inverse_kinematic(self.xt, self.yt, self.zt, self.mode)

        self.get_logger().info(f'Current mode = {self.mode}')
        # self.check_if_reached()
        
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
            self.target_joint_positions = [q_sol_ik_LM[0], q_sol_ik_LM[1], q_sol_ik_LM[2]]
            self.get_logger().info('Taskspace is in workspace')
            return self.target_joint_positions
        else:
            self.get_logger().warn("Taskspace isn't in workspace. Please key again.")
            # self.finish = True
            return self.target_joint_positions
        
    def update_joint_states(self):
        if self.mode != 3:
            return 

        # PID
        smoothed_positions = []
        for i in range(3):
            current_pos = self.current_joint_positions[i]
            target_pos = self.target_joint_positions[i]
            smoothed_pos = self.pid_controllers[i].compute(target_pos, current_pos)
            new_position = current_pos + smoothed_pos * self.dt
            smoothed_positions.append(new_position)

        # Update positions
        self.current_joint_positions = smoothed_positions

        self.joint_msg = JointState()
        self.joint_msg.name = ['joint_1', 'joint_2', 'joint_3']
        self.joint_msg.header.stamp = self.get_clock().now().to_msg()
        self.joint_msg.position = smoothed_positions
        # self.get_logger().info(f'target joint position = {self.target_joint_positions}')

        self.joint_state_pub.publish(self.joint_msg)

    def check_target_reached(self):
        distance = np.sqrt((self.xt - self.xe) ** 2 +
                           (self.yt - self.ye) ** 2 +
                           (self.zt - self.ze) ** 2)
        # self.get_logger().info(f'distance = {distance}, tolerance = {self.tolerance}, logic = {distance <= self.tolerance}')
        return distance <= self.tolerance
    
    def check_if_reached(self):
        if self.check_target_reached():
            self.finish = True
            self.get_logger().info(f'Target reached. finish = {self.finish}')
        else:
            self.finish = False
            self.get_logger().info(f'Target not reached. finish = {self.finish}.')
        
    


def main(args=None):
    rclpy.init(args=args)
    node = Auto()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
