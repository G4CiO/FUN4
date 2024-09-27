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
# from geometry_msgs.msg import TransformStamped, PoseStamped
from fun4_interfaces.srv import ChangeMode
# from tf_transformations import euler_from_quaternion

class InversePoseKinematics(Node):

    def __init__(self):
        super().__init__('inverse_pose_kinematics')
        self.get_logger().info('inverse pose kinematics node has start')
        # Pub
        self.joint_state_pub = self.create_publisher(JointState, '/joint_states', 10)
        # Sub
        # self.target_sub = self.create_subscription(PoseStamped, '/target', self.callback_target, 10)

        # Service Server (รับ mode เข้ามา)
        self.take_mode = self.create_service(ChangeMode, '/mode_pose', self.callback_user)

        # Innitial
        self.mode = 0
        self.x ,self.y, self.z = 0.0, 0.0, 0.0
        self.finish = None
        self.r_min = 0.03
        self.r_max = 0.535
        self.answer = []

    def callback_user(self,request:ChangeMode.Request, response:ChangeMode.Response): # รับ
        mode = request.mode
        x = request.pose.x
        y = request.pose.y
        z = request.pose.z

        self.q_sol = self.inverse_kinematic(x, y, z, mode)

        response.success = self.finish
        response.config = self.q_sol
        return response

    def inverse_kinematic(self, x, y, z, mode):
        distance_squared = x**2 + y**2 + (z-0.2)**2
        if mode == 1 and self.r_min**2 <= distance_squared <= self.r_max**2:

            robot = rtb.DHRobot(
                [
                    rtb.RevoluteMDH(alpha = 0.0,a = 0.0,d = 0.2,offset = 0.0),
                    rtb.RevoluteMDH(alpha = pi/2,a = 0.0,d = 0.02,offset = 0.0),
                    rtb.RevoluteMDH(alpha = 0,a = 0.25,d = 0.0,offset = 0.0),

                ],tool = SE3.Tx(0.28),
                name = "RRR_Robot"
            )

            # Desired end effector pose
            T_Position = SE3(x, y, z)
            q_sol_ik_LM, *_ = robot.ikine_LM(T_Position,mask=[1,1,1,0,0,0],joint_limits=False,q0=[0,0,0])

            Te = robot.fkine(q_sol_ik_LM)
            self.get_logger().info(f'{Te}')

            joint_msg = JointState()
            joint_msg.name = ['joint_1', 'joint_2','joint_3']

            # Initialize the 'position' list with 3 elements
            joint_msg.position = [0.0] * 3  # Ensure the list has enough elements
            joint_msg.header.stamp = self.get_clock().now().to_msg()
            joint_msg.position = [q_sol_ik_LM[0],q_sol_ik_LM[1],q_sol_ik_LM[2]]

            self.joint_state_pub.publish(joint_msg)
            self.finish = True

            self.answer = [q_sol_ik_LM[0], q_sol_ik_LM[1], q_sol_ik_LM[2]]

            self.get_logger().info('call finish')

            return self.answer
        else:
            self.finish = False
            self.get_logger().info('call not finish')
            return self.answer
    


def main(args=None):
    rclpy.init(args=args)
    node = InversePoseKinematics()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
