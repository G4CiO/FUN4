#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import numpy as np
from fun4_interfaces.srv import RunAuto

class RandomTarget(Node):
    def __init__(self):
        super().__init__('random_target')
        self.get_logger().info('random target node has been started')
        # Pub
        self.pose_end_pub = self.create_publisher(PoseStamped, "/target", 10)
        # timer
        self.dt = 0.01
        self.create_timer(self.dt,self.random_target_pub)
        # Service server
        self.random_target_server = self.create_service(RunAuto, '/target_server', self.callback_random_target)
        # Innitial
        self.finish_target = True
        self.xt,self.yt,self.zt = 0.0,0.0,0.0
        self.xr,self.yr,self.zr = 0.0,0.0,0.0
        self.r_min = 0.03
        self.r_max = 0.535

    def random_target_pub(self):
        self.gen_random_ws()
    
    def gen_random_ws(self):
        x = np.random.uniform(-self.r_max, self.r_max)
        y = np.random.uniform(-self.r_max, self.r_max)
        z = np.random.uniform(-self.r_max, self.r_max)
        distance_squared = x**2 + y**2 + (z-0.2)**2
        if self.r_min**2 <= distance_squared <= self.r_max**2:
            self.xr = x
            self.yr = y
            self.zr = z

    def pub_random_target(self):
        
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "link_0"
        msg.pose.position.x = self.xr
        msg.pose.position.y = self.yr
        msg.pose.position.z = self.zr
        self.pose_end_pub.publish(msg)

    def callback_random_target(self,request:RunAuto.Request,response:RunAuto.Response):
        if request.reach_target == True:
            self.pub_random_target()

            response.target.x = self.xr
            response.target.y = self.yr
            response.target.z = self.zr

        return response
        
def main(args=None):
    rclpy.init(args=args)
    node = RandomTarget()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()