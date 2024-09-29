#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import numpy as np
from fun4_interfaces.srv import RunAuto
from functools import partial

class ClientServer(Node):
    def __init__(self):
        super().__init__('client_server')
        self.sub_random_target = self.create_subscription(PoseStamped, '/target',self.callback_random_target,10)
        self.send_target = self.create_client(RunAuto, '/target_')
        self.finish_target = True

    def callback_random_target(self,msg:PoseStamped):
        xt = msg.pose.position.x
        yt = msg.pose.position.y
        zt = msg.pose.position.z
        if self.finish_target:
            self.call_auto(xt,yt,zt)

    def call_auto(self, x, y, z):
        while not self.send_target.wait_for_service(10.0):
            self.get_logger().warn("Waiting for Server Auto Node...")   
            
        
        self.get_logger().info(f'Sending target to auto: ({x}, {y}, {z})')  # Add logging here

        request_position = RunAuto.Request()
        request_position.target.x = x
        request_position.target.y = y
        request_position.target.z = z

        future = self.send_target.call_async(request_position)
        future.add_done_callback(self.callback_auto_response)
        # future.add_done_callback(partial(self.callback_auto_response, x=x, y=y,z=z))

        self.get_logger().info(f'Auto node request sent, waiting for response...')
        

    def callback_auto_response(self, future):
        try:
            response = future.result()
            self.get_logger().info(f"Received response from auto: {response.reach_target}")  # Add logging
            self.finish_target = response.reach_target

            # Allow new targets to be sent again after processing the current one
            self.get_logger().info(f'Processed target. Setting finish_target back to True.')

            if self.finish_target:
                self.get_logger().info(f'Target reached successfully.')
                # self.waiting_for_response = False
            else:
                self.get_logger().warn(f'Target not reached. Setting finish to {self.finish_target}.')
                
           # Now have a response, allow new targets to be sent
            # self.waiting_for_response = False
        except Exception as e:
            self.get_logger().error(f"Service call failed: {str(e)}")

    

def main(args=None):
    rclpy.init(args=args)
    node = ClientServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
