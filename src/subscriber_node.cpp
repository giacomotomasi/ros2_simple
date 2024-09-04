#include "ros2_simple/MarkerSubscriber.hpp"

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ros2_simple::MarkerSubscriber>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}