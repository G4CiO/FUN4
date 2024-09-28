#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import numpy as np
from fun4_interfaces.srv import RunAuto
from functools import partial

class RandomTarget(Node):
    def __init__(self):
        super().__init__('random_target')
        self.pose_end_pub = self.create_publisher(PoseStamped, "/target", 10)
        self.dt = 0.01
        self.create_timer(self.dt, self.random_target)
        self.send_target = self.create_client(RunAuto, '/target_')
        self.finish = True

    def call_auto(self, x, y, z):
        while not self.send_target.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server Auto Node...")   
        request_position = RunAuto.Request()
        request_position.target.x = x
        request_position.target.y = y
        request_position.target.z = z

        # Call the service asynchronously
        future = self.send_target.call_async(request_position)
        
        # Add a callback for when the response is received
        # future.add_done_callback(self.callback_auto_response)
        future.add_done_callback(partial(self.callback_auto_response, x=x, y=y, z=z))
        

    def callback_auto_response(self, future):
        try:
            response = future.result()
            self.finish = response.reach_target
            if self.finish:
                self.get_logger().info('Target reached successfully.')
            else:
                self.get_logger().warn('Target not reached.')
        except Exception as e:
            self.get_logger().error(f"Service call failed: {str(e)}")


    def random_target(self):
        r_min = 0.03
        r_max = 0.535
        
        while True:
            # Generate random values for x, y, z
            x = np.random.uniform(-r_max, r_max)
            y = np.random.uniform(-r_max, r_max)
            z = np.random.uniform(-r_max, r_max)

            # Check if the generated point is within the spherical range
            distance_squared = x**2 + y**2 + (z-0.2)**2
            
            if r_min**2 <= distance_squared <= r_max**2:
                # Create a PoseStamped message and fill in the values
                msg = PoseStamped()
                msg.header.stamp = self.get_clock().now().to_msg()
                msg.header.frame_id = "end_effector"  # Set your desired frame id

                # Set position
                msg.pose.position.x = x
                msg.pose.position.y = y
                msg.pose.position.z = z
                
                # Set orientation to default (no rotation)
                msg.pose.orientation.x = 0.0
                msg.pose.orientation.y = 0.0
                msg.pose.orientation.z = 0.0
                msg.pose.orientation.w = 1.0

                self.pose_end_pub.publish(msg)

                self.call_auto(x, y, z)

                break  # Exit the loop after successfully publishing

def main(args=None):
    rclpy.init(args=args)
    node = RandomTarget()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
