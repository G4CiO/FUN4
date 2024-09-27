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

class Teleoperation(Node):

    def __init__(self):
        super().__init__('teleoperation')
        self.get_logger().info('teleoperation node has start')
    


def main(args=None):
    rclpy.init(args=args)
    node = Teleoperation()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
