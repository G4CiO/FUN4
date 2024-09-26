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
from tf_transformations import quaternion_from_matrix

class EndEffectorPose(Node):

    def __init__(self):
        super().__init__('end_effector_pose')

        # Create a buffer and listener for transforms
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Create a publisher for the PoseStamped message
        self.pose_pub = self.create_publisher(PoseStamped, '/end_effector', 10)
        # Create a Subscriber tf
        self.joint_sub = self.create_subscription(JointState, '/joint_states', self.callback_joint_state, 10)
        # Set the source and target frames (replace with your frames)
        self.source_frame = 'link_0'
        self.target_frame = 'end_effector'

        # Timer to periodically check for transform
        # self.timer = self.create_timer(0.01, self.get_transform)

    def callback_joint_state(self, msg: JointState):
        joint_1 = msg.position[0]
        joint_2 = msg.position[1]
        joint_3 = msg.position[2]
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
        # หา Forward kinematic ที่จุด Home Configuration
        q = [joint_1,joint_2,0,joint_3,0] # สร้างค่า q

        self.T_0e = robot.fkine(q) # ใส่ค่า q ลงในตาราง DH
        self.get_logger().info(f'{self.T_0e}')

        # Create a PoseStamped message
        pose_msg = PoseStamped()

        # Fill in the PoseStamped message based on the TransformStamped data
        pose_msg.header.stamp = self.get_clock().now().to_msg()
        pose_msg.header.frame_id = self.target_frame
        
        # Set the position (translation)
        pose_msg.pose.position.x = self.T_0e.x
        pose_msg.pose.position.y = self.T_0e.y
        pose_msg.pose.position.z = self.T_0e.z

        # Set the orientation (rotation)
        orientation_quat = quaternion_from_matrix(self.T_0e)
        pose_msg.pose.orientation.x = orientation_quat[0]
        pose_msg.pose.orientation.y = orientation_quat[1]
        pose_msg.pose.orientation.z = orientation_quat[2]
        pose_msg.pose.orientation.w = orientation_quat[3]

        self.pose_pub.publish(pose_msg)


    # def get_transform(self):
    #     try:
    #         # Look up the latest transform between source_frame and target_frame
    #         now = rclpy.time.Time()
    #         transform = self.tf_buffer.lookup_transform('end_effector', 'link_0', now)
    #         self.publish_pose(transform)

    #     except Exception as e:
    #         self.get_logger().warn(f'Could not get transform: {e}')

    # def publish_pose(self, transform: TransformStamped):

    #     # Create a PoseStamped message
    #     pose_msg = PoseStamped()
        
    #     # Fill in the PoseStamped message based on the TransformStamped data
    #     pose_msg.header.stamp = self.get_clock().now().to_msg()
    #     pose_msg.header.frame_id = self.target_frame
        
    #     # Set the position (translation)
    #     pose_msg.pose.position.x = transform.transform.translation.x
    #     pose_msg.pose.position.y = transform.transform.translation.y
    #     pose_msg.pose.position.z = transform.transform.translation.z
        
    #     # Set the orientation (rotation)
    #     pose_msg.pose.orientation = transform.transform.rotation

    #     # Publish the PoseStamped message
    #     self.pose_pub.publish(pose_msg)

def main(args=None):
    rclpy.init(args=args)
    node = EndEffectorPose()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
