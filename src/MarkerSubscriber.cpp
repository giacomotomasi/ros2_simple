#include "ros2_simple/MarkerSubscriber.hpp"

namespace ros2_simple
{
    MarkerSubscriber::MarkerSubscriber() : Node("marker_subscriber_node")
    {
        RCLCPP_INFO(this->get_logger(), "Subscriber created.");

        marker_sub_ = this->create_subscription<visualization_msgs::msg::Marker>("marker_topic", 10, std::bind(&MarkerSubscriber::markerCallback, this, std::placeholders::_1));
        // Initialize timer
        timer_start_ = this->now();
    }

    MarkerSubscriber::~MarkerSubscriber()
    {
        RCLCPP_INFO(this->get_logger(), "Subscriber destroyed.");
    }

    void MarkerSubscriber::markerCallback(const visualization_msgs::msg::Marker::SharedPtr marker_msg)
    {
        rclcpp::Time timer_end = this->now();
        RCLCPP_INFO(this->get_logger(), "Elapsed time: %f ms. Marker position: (%f, %f, %f).", (timer_end - timer_start_).seconds() * 1000.0f, marker_msg->pose.position.x, marker_msg->pose.position.y, marker_msg->pose.position.z);
        timer_start_ = timer_end;
    }
}