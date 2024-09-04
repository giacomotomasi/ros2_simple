#pragma once

#include "rclcpp/rclcpp.hpp"
#include "visualization_msgs/msg/marker.hpp"

namespace ros2_simple {
    class MarkerSubscriber : public rclcpp::Node {
        public:
        // Constructor
        MarkerSubscriber();
        // Destructor
        ~MarkerSubscriber();

        private:
        /// Declare subscriber
        rclcpp::Subscription<visualization_msgs::msg::Marker>::SharedPtr _marker_sub;
        /// Variable to count elapsed time
        rclcpp::Time _timer_start {};

        /**
         * Marker callback.
         */
        void markerCallback(const visualization_msgs::msg::Marker::SharedPtr marker_msg);
    };
}