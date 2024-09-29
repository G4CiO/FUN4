#!/usr/bin/python3

import rclpy
from rclpy.executors import MultiThreadedExecutor
from auto import Auto  # Assuming 'Auto' is defined in auto.py
from random_target import RandomTarget  # Assuming 'RandomTarget' is defined in random_target.py

def main(args=None):
    rclpy.init(args=args)

    # Initialize both nodes
    auto_node = Auto()
    random_target_node = RandomTarget()

    # Use a MultiThreadedExecutor
    executor = MultiThreadedExecutor()
    
    # Add nodes to the executor
    executor.add_node(auto_node)
    executor.add_node(random_target_node)

    try:
        executor.spin()
    finally:
        # Clean up nodes and shut down properly
        auto_node.destroy_node()
        random_target_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
