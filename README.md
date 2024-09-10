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

## How to use
Quick instructions how to use the package.

#### Build the package
Clone the package inside the `src` directory of your `ros2 workspace`. From the workspace directory run:
```
colcon build --packages-select ros2_simple
```

#### Run Publisher
To run the MarkerPublisher node with **default parameters**, use the command:
```
ros2 run ros2_simple marker_pub_node
```

To run the MarkerPublisher node loading **custom parameters** from a `params.yaml`, file use the command:
```
ros2 run ros2_simple marker_pub_node --ros-args --params-file /path/to/params.yaml
```
If you run the command from your workspace directory, the path would be `src/ros2_simple/config/params.yaml`.

#### Run Subscriber
To run the MarkerSubscriber node, use the command:
```
ros2 run ros2_simple marker_sub_node
```

#### Run via launch file
A launch file is available in the directoty `/config` inside `ros2_simple` package. This file will launch both MarkerPublisher and MarkerSubscriber nodes and it will load the `params.yaml` file, i.e. the **custom parameters**. \
To launch the whole package use the command:
```
ros2 launch ros2_simple marker_launch.py
```

## Testing
To be developed..


