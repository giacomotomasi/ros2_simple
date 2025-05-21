#include "ros2_simple/MarkerPublisher.hpp"
#include "rclcpp/rclcpp.hpp"

namespace ros2_simple
{

    MarkerPublisher::MarkerPublisher() : Node("marker_publisher_node")
    {
        // Default parameters
        this->declare_parameter<int>("publisher_frequency", 1);
        this->declare_parameter<double>("speed", 0.1);
        // Assign parameters
        this->get_parameter("publisher_frequency", pub_frequency_);
        this->get_parameter("speed", speed_);

        RCLCPP_DEBUG(this->get_logger(), "publisher_frequency: %i", pub_frequency_);
        RCLCPP_DEBUG(this->get_logger(), "speed: %f", speed_);

        // Create marker MarkerPublisher
        marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("marker_topic", 10);
        // Create time callback
        if (pub_frequency_ > 1000)
        {
            pub_frequency_ = 1000;
            RCLCPP_WARN(this->get_logger(), "The frequency is too high, it will be set to 1000Hz (1 millisecond).");
        }
        int duration = 1000 / pub_frequency_;
        RCLCPP_INFO(this->get_logger(), "The duration is %d milliseconds.", duration);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(duration), std::bind(&ros2_simple::MarkerPublisher::timerCallback, this));

        // Define marker
        marker_.header.frame_id = "map";
        marker_.header.stamp = this->now();
        marker_.ns = "simple_marker";
        marker_.id = 0;
        marker_.type = visualization_msgs::msg::Marker::CUBE;
        marker_.action = visualization_msgs::msg::Marker::ADD;
        marker_.scale.x = 0.5;
        marker_.scale.y = 0.25;
        marker_.scale.z = 0.2;
        marker_.pose.position.x = marker_.scale.x / 2.0;
        marker_.pose.position.y = 0.0;
        marker_.pose.position.z = marker_.scale.z / 2.0;
        marker_.pose.orientation.x = 0.0;
        marker_.pose.orientation.y = 0.0;
        marker_.pose.orientation.z = 0.0;
        marker_.pose.orientation.w = 1.0;
        marker_.color.r = 0.0f;
        marker_.color.g = 1.0f;
        marker_.color.b = 0.0f;
        marker_.color.a = 1.0f;
        marker_.lifetime = rclcpp::Duration::from_seconds(1 / pub_frequency_);
        RCLCPP_INFO(this->get_logger(), "Publisher created.");
    }

    MarkerPublisher::~MarkerPublisher()
    {
        RCLCPP_INFO(this->get_logger(), "Publisher destroyed.");
    }

    void MarkerPublisher::timerCallback()
    {
        updateMarker();
        marker_pub_->publish(marker_);
        RCLCPP_INFO(this->get_logger(), "Marker message published.");
    }

    void MarkerPublisher::MarkerPublisher::updateMarker()
    {
        // Shift the marker x position by a certain quantity that depends on the speed and frequency of update.
        double shift{speed_ / pub_frequency_};
        marker_.pose.position.x += shift;
        // Update timestamp
        marker_.header.stamp = this->now();
    }

    visualization_msgs::msg::Marker MarkerPublisher::getMarker()
    {
        return marker_;
    }

    void MarkerPublisher::setFrequency(int frequency)
    {
        pub_frequency_ = frequency;
    }

    void MarkerPublisher::setSpeed(double speed)
    {
        speed_ = speed;
    }
}