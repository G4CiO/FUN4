#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from math import pi
# from spatialmath import *
import numpy as np

class RnadomTarget(Node):
    def __init__(self):
        super().__init__('random_target')
        self.pose_end_pub = self.create_publisher(PoseStamped, "/target", 10)
        self.dt = 0.01
        self.create_timer(self.dt, self.sim_loop)
        self.pos = [0.0, 0.0, 0.0]
        self.cmd_vel = [0.0, 0.0, 0.0]
        self.name = ["joint_1", "joint_2", "joint_3"]

    def sim_loop(self):
        msg = PoseStamped()

        msg.header.stamp = self.get_clock().now().to_msg()
        q_d = [0.1, 0.1, 0.1]

        self.pos[0] = self.pos[0] + (q_d[0] * self.dt)
        self.pos[1] = self.pos[1] + (q_d[1] * self.dt)
        self.pos[2] = self.pos[2] + (q_d[2] * self.dt)

        msg.pose.position.x = self.pos[0]
        msg.pose.position.y = self.pos[1]
        msg.pose.position.z = self.pos[2]
        self.pose_end_pub.publish(msg)
        
def main(args=None):
    rclpy.init(args=args)
    node = RnadomTarget()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__=='__main__':
    main()
