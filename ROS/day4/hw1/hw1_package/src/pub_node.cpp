
#include "../include/day4_hw1/publisher.hpp"

using namespace std::chrono_literals;

Pub::Pub()
    // : Node("minimal_publisher"), count_(0)
    : rclcpp_lifecycle::LifecycleNode("pub"), count(0)
{
    // publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    // timer_ = this->create_wall_timer(
    //     500ms, std::bind(&MinimalPublisher::timer_callback, this));
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Pub::on_configure(const rclcpp_lifecycle::State &state)
{//위 줄 코드--> 퍼블리셔, 타이머 생성
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    publisher = this->create_publisher<std_msgs::msg::String>("topicname", qos_profile);
    timer = this->create_wall_timer(1s, std::bind(&Pub::timer_callback, this));

    RCUTILS_LOG_INFO_NAMED(get_name(), "on_configure() is called from state %s.", state.label().c_str());

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Pub::on_activate(const rclcpp_lifecycle::State &state)
{

    publisher->on_activate();

    RCUTILS_LOG_INFO_NAMED(get_name(), "on_activate() is called from state %s.", state.label().c_str());

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Pub::on_deactivate(const rclcpp_lifecycle::State &state)
{
    publisher->on_deactivate();

    RCUTILS_LOG_INFO_NAMED(get_name(), "on_deactivate() is called from state %s.", state.label().c_str());

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Pub::on_cleanup(const rclcpp_lifecycle::State &state)
{

    timer.reset();
    publisher.reset();

    RCUTILS_LOG_INFO_NAMED(get_name(), "on cleanup is called from state %s.", state.label().c_str());

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn Pub::on_shutdown(const rclcpp_lifecycle::State &state)
{

    timer.reset();
    publisher.reset();

    RCUTILS_LOG_INFO_NAMED(get_name(), "on shutdown is called from state %s.", state.label().c_str());

    return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
}

void Pub::timer_callback()
{
    auto message = std_msgs::msg::String();
    message.data = "Say Hello #" + std::to_string(count++);
    // Print the current  for demo purposes
    if (!publisher->is_activated())
    {
        RCLCPP_INFO(
            get_logger(), "Lifecycle publisher is currently inactive. Messages are not published.");
    }
    else
    {
        RCLCPP_INFO(get_logger(), "Lifecycle publisher is active. Publishing: [%s]", message.data.c_str());
    }

    // We independently from the current state call publish on the lifecycle
    // publisher.
    // Only if the publisher is in an active state, the message transfer is
    // enabled and the message actually published.
    publisher->publish(message);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    std::shared_ptr<Pub> pub = std::make_shared<Pub>();
    rclcpp::spin(pub->get_node_base_interface());
    // rclcpp::spin(std::make_shared<MinimalPublisher>()); //origianl
    rclcpp::shutdown();
    return 0;
}
