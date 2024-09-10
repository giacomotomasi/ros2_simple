# ros2_simple package

Simple ROS2 package containing basic nodes fthat can be used as example and/or to test the new environment. It contains:
* a publisher node that updates the position of a marker (cube) shifting it to x-coordinate of a certain amount. 
* a subscriber node that subscribes to the marker topic and displays the elaspled time between messages.

### Topics
Topic name: `/marker_topic`. \
Message type: `visualization_msgs::msg::Marker`.

### Parameters
Parameters are configurable in `/config/params.yaml`. 
* **publisher_frequency**: frequency of marker position update [Hz].
* **speed**: speed of the marker [m/s]. This is used with the frequency to compute the shift to apply to the new marker message.



