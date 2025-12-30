#!/bin/bash

# Launch publisher and subscriber nodes with cleanup handle

cleanup() {
    echo "Restarting ROS2 daemon to clean up before shutting down"
    ros2 daemon stop
    sleep 1
    ros2 daemon start
    echo "Terminating all ROS 2- related processes..."
    kill 0  # KILLS ALL PROCESSES
    exit
}

trap 'cleanup' SIGINT

#Launch the publisher
ros2 run ros2_fundamentals_examples my_minimal_publisher.py&

sleep 2

#Launch the subscriber
ros2 run ros2_fundamentals_examples my_minimal_subscriber.py& 

wait