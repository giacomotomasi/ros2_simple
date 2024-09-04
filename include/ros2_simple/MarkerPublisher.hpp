#pragma once

#include "iostream"
#include "rclcpp/rclcpp.hpp"
#include "visualization_msgs/msg/marker.hpp"

namespace ros2_simple {
    class MarkerPublisher : public rclcpp::Node {
        public:
            // Constructor
            MarkerPublisher();
            // Destructor
            ~MarkerPublisher();

            /**
             * Getter for Marker.
             */
            visualization_msgs::msg::Marker getMarker();

            /**
             * Set frequency parameter.
             */
            void setFrequency(int frequency);

            /**
             * Set speed parameter.
             */
            void setSpeed(double speed);

            /**
             * Shift the marker x position ti create a motion for visualization.
             */
            void updateMarker();

        private:
            // Declare publisher
            rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr _marker_pub;
            rclcpp::TimerBase::SharedPtr _timer;

            // Create a marker instance
            visualization_msgs::msg::Marker _marker {};

            int _pub_frequency {};
            double _speed {};

            /**
             * Timer callback.
             */
            void timerCallback();
    };

}

