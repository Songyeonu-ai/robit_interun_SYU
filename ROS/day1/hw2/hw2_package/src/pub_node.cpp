// // #include "publisher.hpp"

// // void MyCppNode::timer_callback()
// // {
// //     auto msg = std_msgs::msg::String();
// //     msg.data = "Hello World: " + std::to_string(count++);
// //     RCLCPP_INFO(this->get_logger(), "Published message: '%s'", msg.data.c_str());
// //     mycpp_publisher_->publishe(msg);
// // }

// // MyNode::MyNode(): Node("mynode")
// // {
// //     publisher = this->create_publisher<std_msgs::msg::String>("topicname", 10);
// // }
// // MyNode::~MyNode()
// // {
    
// // }
#include <chrono>
#include <functional>
#include <memory>
#include <string>


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Pub : public rclcpp::Node
{
    public:
       Pub() : Node("pub")//, count(0)
       {
           //auto qos_profile = rclcpp::Qos(rclcpp::KeepLast(10));
           publisher = this->create_publisher<std_msgs::msg::String>("topicname", 10);
           timer = this->create_wall_timer(1s, std::bind(&Pub::timer_callback,this));
       }
       int count=0;

    private:
        rclcpp::TimerBase::SharedPtr timer;
       void timer_callback()
       {
           auto msg = std_msgs::msg::String();
           msg.data = "Hello World: " + std::to_string(count++);
           RCLCPP_INFO(this->get_logger(), "Published message: '%s'", msg.data.c_str());
           publisher->publish(msg);
       }
       rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher;
};


// // mycpp_publisher_ = this->create_publisher<std_msg::String>("topicname", 10);
// // timer_ = this->create_wall_timer(1s, std::bind(&MyCppNode::timer_callback, this));

// // private:
// //     rclcpp::TimerBase::SharePtr timer_;
// //     void timer_callback();
 
// //     rclcpp::Publisher<std_msgs::msg::Strimg>::SharePtr mycpp_publisher_;

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); //ROS 초기화하는 과정...노드의 이름을 갖게 됨
    auto node = std::make_shared<Pub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}


