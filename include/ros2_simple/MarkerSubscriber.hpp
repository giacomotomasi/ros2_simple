#pragma once

#include "rclcpp/rclcpp.hpp"
#include "visualization_msgs/msg/marker.hpp"

namespace ros2_simple
{
    class MarkerSubscriber : public rclcpp::Node
    {
    public:
        /// @brief Constructor
        MarkerSubscriber();
        /// @brief Destructor
        ~MarkerSubscriber();

    private:
        /// @brief Declare subscriber
        rclcpp::Subscription<visualization_msgs::msg::Marker>::SharedPtr marker_sub_;
        /// @brief Variable to count elapsed time
        rclcpp::Time timer_start_{};

        /// @brief Marker callback
        void markerCallback(const visualization_msgs::msg::Marker::SharedPtr marker_msg);
    };
}