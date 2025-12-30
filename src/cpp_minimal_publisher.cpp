/**
 * 
 * 
 */
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalCppPublisher : public rclcpp::Node {

public:
    MinimalCppPublisher() : Node("minimal_cpp_publisher"), count(0)
    {
        publisher_ = create_publisher<std_msgs::msg::String>(
            "/cpp_example_topic", 10);

        timer_ = create_wall_timer(500ms, 
            std::bind(&MinimalCppPublisher::timerCallback, this));
        
        RCLCPP_INFO(get_logger(), "Publishing at 2HZ");
            
    }

    void timerCallback() {
        auto message = std_msgs::msg::String();
        message.data = "Hello World! " + std::to_string(count++); 

        publisher_->publish(message);
    }
private:
    size_t count; //keep track of the number of messages published
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr
    publisher_; // the publisher obj
    rclcpp::TimerBase::SharedPtr timer_;

};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    
    auto minimal_cpp_publisher_node = std::make_shared<MinimalCppPublisher>();
    rclcpp::spin(minimal_cpp_publisher_node);
    rclcpp::shutdown();

    return 0;
}