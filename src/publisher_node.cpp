#include "ros2_simple/MarkerPublisher.hpp"


int main(int argc, char **argv){
    rclcpp::init(argc, argv);

    auto node = std::make_shared<ros2_simple::MarkerPublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();
}