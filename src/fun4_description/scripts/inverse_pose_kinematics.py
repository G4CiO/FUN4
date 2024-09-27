#!/usr/bin/python3
import roboticstoolbox as rtb
import numpy as np


from sensor_msgs.msg import JointState
from spatialmath import SE3
from math import pi
from math import radians
import rclpy
from rclpy.node import Node
from tf2_ros import Buffer, TransformListener
from geometry_msgs.msg import TransformStamped, PoseStamped
from tf_transformations import euler_from_quaternion

class InversePoseKinematics(Node):

    def __init__(self):
        super().__init__('inverse_pose_kinematics')
        # Pub
        self.joint_state_pub = self.create_publisher(JointState, '/joint_states', 10)
        # Sub
        self.target_sub = self.create_subscription(PoseStamped, '/target', self.callback_target, 10)
        # Service

    def callback_target(self, msg:PoseStamped):
        x = msg.pose.position.x
        y = msg.pose.position.y
        z = msg.pose.position.z

        xq = msg.pose.orientation.x
        yq = msg.pose.orientation.y
        zq = msg.pose.orientation.z
        w = msg.pose.orientation.w

        q = euler_from_quaternion([xq,yq,zq,w])

        robot = rtb.DHRobot(
            [
                rtb.RevoluteMDH(d=0.2), # Joint1
                rtb.RevoluteMDH(alpha=-pi/2,d=-0.12), # Joint2
                rtb.RevoluteMDH(alpha=pi/2,d=0.25), # JointN
                rtb.RevoluteMDH(alpha=-pi/2,d=0.1), # Joint3
                rtb.RevoluteMDH(alpha=pi/2,d=0.28), # e
            ],
            name = "RRR_Robot" # เขียนชื่อหุ่นยนต์ 
        )

        # Desired end effector pose
        T_Position = SE3(x, y, z)
        # Desired end effector oren
        T_Orentation = SE3.RPY([q[0],q[1],q[2]], order='zyx')
        # TF of End-Effector
        T_desired = T_Position @ T_Orentation
        q_sol_ik_LM, *_ = robot.ikine_LM(T_desired)
        self.get_logger
        joint_msg = JointState()

        joint_msg.name = ['joint_1', 'joint_2','joint_3']
        joint_msg.position[0] = q_sol_ik_LM[0]
        joint_msg.position[1] = q_sol_ik_LM[1]
        joint_msg.position[2] = q_sol_ik_LM[3]

        self.joint_state_pub.publish(joint_msg)

def main(args=None):
    rclpy.init(args=args)
    node = InversePoseKinematics()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
