
#include <chrono>
#include <functional>
#include <memory>
#include <string>


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int64.hpp"
#include "std_msgs/msg/float64.hpp"

class Sub : public rclcpp::Node
{
    public:
       Sub() : Node("sub")
        {
                subscriber = this ->create_subscription<std_msgs::msg::Int64>(
                "topicname", 
                10,
                std::bind(&Sub::topic_callback1, this, std::placeholders::_1));
        }

    private:
       void topic_callback1(const std_msgs::msg::Int64::SharedPtr msg1)
       {
           RCLCPP_INFO(this->get_logger(), "Received message: '%ld'", msg1->data);
       }
       rclcpp::Subscription<std_msgs::msg::Int64>::SharedPtr subscriber;

};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Sub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}