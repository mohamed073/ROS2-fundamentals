#!/usr/bin/env python3

"""
Description:
    This ROS2 node periodically subscribes to "HELLO WORLD" message.
---------
publishing Topics: None
---------------
Subscription Topics:
    /py_example_topic - std_msgs.msg.String
----------------
Author: Mo
Date: 28/12/2025
"""
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class MinimalPySubscriber(Node):
    def __init__(self):
        super().__init__('minimal_py_subscriber')
        self.subscription = self.create_subscription(  # Fixed variable name
            String,
            '/py_example_topic',
            self.listener_callback,
            10
        )
        self.subscription  # Prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info(f'I heard: "{msg.data}"')

def main(args=None):
    rclpy.init(args=args)
    minimal_py_subscriber = MinimalPySubscriber()
    rclpy.spin(minimal_py_subscriber)
    minimal_py_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
