#include "ros2_simple/MarkerPublisher.hpp"
#include "rclcpp/rclcpp.hpp"


namespace ros2_simple {

    MarkerPublisher::MarkerPublisher() : Node("marker_publisher_node"){
        // Default parameters
        this->declare_parameter<int>("publisher_frequency", 1);
        this->declare_parameter<double>("speed", 0.1);
        // Assign parameters
        this->get_parameter("publisher_frequency", _pub_frequency);
        this->get_parameter("speed", _speed);
        //TODO: remove print statement
        std::cout << "Publish frequency: " << _pub_frequency << std::endl;

        // Create marker MarkerPublisher
        _marker_pub = this->create_publisher<visualization_msgs::msg::Marker>("marker_topic", 10);
        // Create time callback
        if (_pub_frequency > 1000) {
            _pub_frequency = 1000;
            RCLCPP_WARN(this->get_logger(), "The frequency is too high, it will be set to 1000Hz (1 millisecond).");
        }
        int duration = 1000 / _pub_frequency;
        RCLCPP_INFO(this->get_logger(), "The duration is %d milliseconds.", duration);
        _timer = this->create_wall_timer(std::chrono::milliseconds(duration), std::bind(&ros2_simple::MarkerPublisher::timerCallback, this));

        // Define marker
        _marker.header.frame_id = "map";
        _marker.header.stamp = this->now();
        _marker.ns = "simple_marker";
        _marker.id = 0;
        _marker.type = visualization_msgs::msg::Marker::CUBE;
        _marker.action = visualization_msgs::msg::Marker::ADD;
        _marker.scale.x = 0.5;
        _marker.scale.y = 0.25;
        _marker.scale.z = 0.2;
        _marker.pose.position.x = _marker.scale.x / 2.0;
        _marker.pose.position.y = 0.0;
        _marker.pose.position.z = _marker.scale.z / 2.0;
        _marker.pose.orientation.x = 0.0;
        _marker.pose.orientation.y = 0.0;
        _marker.pose.orientation.z = 0.0;
        _marker.pose.orientation.w = 1.0;
        _marker.color.r = 0.0f;
        _marker.color.g = 1.0f;
        _marker.color.b = 0.0f;
        _marker.color.a = 1.0f;
        _marker.lifetime = rclcpp::Duration::from_seconds(1/_pub_frequency);
        RCLCPP_INFO(this->get_logger(), "Publisher created.");
    }

    MarkerPublisher::~MarkerPublisher(){
        RCLCPP_INFO(this->get_logger(), "Publisher destroyed.");
    }

    void MarkerPublisher::timerCallback(){
        updateMarker();
        _marker_pub->publish(_marker);
        RCLCPP_INFO(this->get_logger(), "Marker message published.");
    }

    void MarkerPublisher::MarkerPublisher::updateMarker() {
        // Shift the marker x position by a certain quantity that depends on the speed and frequency of update.
        double shift {_speed / _pub_frequency};
        _marker.pose.position.x += shift;
        // Update timestamp
        _marker.header.stamp = this->now();
    }
}