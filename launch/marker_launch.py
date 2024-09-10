import os
from ament_index_python.packages import get_package_share_directory
import launch
import launch_ros.actions

def generate_launch_description():
    ld = launch.LaunchDescription()

    """
    DEBUG,INFO,WARN,ERROR,FATAL 
    """
    logLevel = "INFO"

    ros2_simple_params = os.path.dirname(
        os.path.dirname(
            os.path.dirname(
                os.path.dirname(
                        get_package_share_directory('ros2_simple'))))) + '/src/ros2_simple/config/params.yaml'

    marker_pub_node = launch_ros.actions.Node(
        package="ros2_simple",
        executable="marker_pub_node",
        name='marker_pub_node',
        # namespace='ros2_simple',
        parameters=[ros2_simple_params],
        arguments=['--ros-args', '--log-level', logLevel],
        output='screen'
    )

    marker_sub_node = launch_ros.actions.Node(
        package="ros2_simple",
        executable="marker_sub_node",
        name='marker_sub_node',
        # namespace='ros2_simple',
        parameters=[ros2_simple_params],
        arguments=['--ros-args', '--log-level', logLevel],
        output='screen'
    )

    ld.add_action(marker_pub_node)
    ld.add_action(marker_sub_node)

    return ld