// // #include "rclcpp/rclcpp.hpp"
// class MyCppNode : public rclcpp::Node
// {
// public:
//     MyCppNode() : Node("my_cpp_node")
//     {
//         RCLCPP_INFO(this->get_logger(), "Hello, ROS 2 C++ Node!");
//     }
// };



#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
class Sub : public rclcpp::Node
{
    public:
       Sub() : Node("sub")
        {
            //auto qos_profile = rclcpp::Qos(rclcpp::KeepLast(10));
            mycpp_subscriber_ = this ->create_subscription<std_msgs::msg::String>(
                "topicname", 
                10,
                std::bind(&Sub::topic_callback, this, std::placeholders::_1));
        }

    private:
       void topic_callback(const std_msgs::msg::String::SharedPtr msg)
       {
           RCLCPP_INFO(this->get_logger(), "Received message: '%s'", msg->data.c_str());
           //publisher_->publish(msg);
       }
       rclcpp::Subscription<std_msgs::msg::String>::SharedPtr mycpp_subscriber_;

};

// void topic_callback(const std_msgs::msg::String::SharedPtr msg)
// {
//     RCLCPP_INFO(this->get_logger(), "Received message: '%s'", msg->data.c_str())
// }

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Sub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
