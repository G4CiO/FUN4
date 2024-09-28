#!/usr/bin/python3
import roboticstoolbox as rtb
import numpy as np

from sensor_msgs.msg import JointState
from spatialmath import SE3
import math
from math import pi
from math import radians
import rclpy
from rclpy.node import Node
from tf2_ros import TransformException
from tf2_ros.buffer import Buffer
from sensor_msgs.msg import JointState
from tf2_ros.transform_listener import TransformListener 
from geometry_msgs.msg import TransformStamped, PoseStamped
from std_msgs.msg import Float64MultiArray
from tf_transformations import quaternion_from_matrix

class EndEffectorPose(Node):

    def __init__(self):
        super().__init__('end_effector_pose')

        # Create a buffer and listener for transforms
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Create a publisher for the PoseStamped message
        self.pose_pub = self.create_publisher(PoseStamped, '/end_effector', 10)
        self.joint_state_pub = self.create_publisher(JointState, '/joint_states', 10)

        self.source_frame = 'link_0'
        self.target_frame = 'end_effector'

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Call on_timer function on a set interval
        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.on_timer)
        
        # Current position and orientation of the target frame with respect to the 
        # reference frame. x and y are in meters, and yaw is in radians.
        self.current_x = 0.0
        self.current_y = 0.0 
        self.current_z = 0.0
        self.current_roll = 0.0
        self.current_pitch = 0.0
        self.current_yaw = 0.0

    def on_timer(self):
        """
        Callback function.
        This function gets called at the specific time interval.
        """
        # Store frame names in variables that will be used to
        # compute transformations
        from_frame_rel = self.target_frame
        to_frame_rel = self.source_frame
    
        trans = None
        
        try:
            now = rclpy.time.Time()
            trans = self.tf_buffer.lookup_transform(
                        to_frame_rel,
                        from_frame_rel,
                        now)
        except TransformException as ex:
            self.get_logger().info(
                f'Could not transform {to_frame_rel} to {from_frame_rel}: {ex}')
            return
        
        # Publish the 2D pose
        current_x = trans.transform.translation.x
        current_y = trans.transform.translation.y
        current_z = trans.transform.translation.z 

        qx = trans.transform.rotation.x
        qy = trans.transform.rotation.y
        qz = trans.transform.rotation.z
        qw = trans.transform.rotation.w

        # Create a PoseStamped message
        pose_msg = PoseStamped()

        # Fill in the PoseStamped message based on the TransformStamped data
        pose_msg.header.stamp = self.get_clock().now().to_msg()
        pose_msg.header.frame_id = self.target_frame
        
        # Set the position (translation)
        pose_msg.pose.position.x = current_x
        pose_msg.pose.position.y = current_y
        pose_msg.pose.position.z = current_z

        # Set the orientation (rotation)
        pose_msg.pose.orientation.x = qx
        pose_msg.pose.orientation.y = qy
        pose_msg.pose.orientation.z = qz
        pose_msg.pose.orientation.w = qw

        self.pose_pub.publish(pose_msg) 

    def euler_from_quaternion(self, x, y, z, w):
        """
        Convert a quaternion into euler angles (roll, pitch, yaw)
        roll is rotation around x in radians (counterclockwise)
        pitch is rotation around y in radians (counterclockwise)
        yaw is rotation around z in radians (counterclockwise)
        """
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll_x = math.atan2(t0, t1)
        
        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = math.asin(t2)
        
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw_z = math.atan2(t3, t4)
        
        return roll_x, pitch_y, yaw_z # in radians

def main(args=None):
    rclpy.init(args=args)
    node = EndEffectorPose()
    # Publish joint message one time during initialization
    joint_msg = JointState()
    joint_msg.name = ['joint_1', 'joint_2', 'joint_3']
    joint_msg.header.stamp = node.get_clock().now().to_msg()
    joint_msg.position = [0.0, 0.0, 0.0]
    node.joint_state_pub.publish(joint_msg)
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
