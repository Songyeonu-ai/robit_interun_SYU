
#include <chrono>
#include <functional>
#include <memory>
#include <string>


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int64.hpp"
#include "std_msgs/msg/float64.hpp"

using namespace std::chrono_literals;
using namespace std;

class Pub : public rclcpp::Node
{
    public:
       Pub() : Node("pub")
       {
           publisher = this->create_publisher<std_msgs::msg::Int64>("topicname", 10);
           timer = this->create_wall_timer(10s, std::bind(&Pub::cmd_user_inp,this));
       }
       int count=0;

    private:
        rclcpp::TimerBase::SharedPtr timer;
       void cmd_user_inp(){
           auto msg = std_msgs::msg::Int64();
           cout<<"아무거나 정수나 입력하세요(10초 후 초기화) :  ";
           cin>>msg.data;
           RCLCPP_INFO(this->get_logger(), "Published message: '%ld'", msg.data);
           publisher->publish(msg);

       }
       rclcpp::Publisher<std_msgs::msg::Int64>::SharedPtr publisher;
};


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); 
    auto node = std::make_shared<Pub>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

