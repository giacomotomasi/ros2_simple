#pragma once

#include "iostream"
#include "rclcpp/rclcpp.hpp"
#include "visualization_msgs/msg/marker.hpp"

namespace ros2_simple
{
    class MarkerPublisher : public rclcpp::Node
    {
    public:
        /// @brief Constructor
        MarkerPublisher();
        /// @brief Destructor
        ~MarkerPublisher();

        /// @brief Getter for Marker
        visualization_msgs::msg::Marker getMarker();

        /// @brief Set frequency paramete
        void setFrequency(int frequency);

        /// @brief Set speed parameter
        void setSpeed(double speed);

        /// @brief Shift the marker x position ti create a motion for visualization
        void updateMarker();

    private:
        /// @brief Declare publisher
        rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
        rclcpp::TimerBase::SharedPtr timer_;

        /// @brief Create a marker instance
        visualization_msgs::msg::Marker marker_{};

        int pub_frequency_{};
        double speed_{};

        /// @brief Timer callback
        void timerCallback();
    };

} // ros2_simple
