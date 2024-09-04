cmake_minimum_required(VERSION 3.8)
project(ros2_simple)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_gtest REQUIRED)
find_package(rclcpp REQUIRED)
find_package(visualization_msgs REQUIRED)

# include_directories(
#         include
#         include/${PROJECT_NAME}
# )

# add executables
add_executable(marker_pub_node src/publisher_node.cpp src/MarkerPublisher.cpp)
add_executable(marker_sub_node src/subscriber_node.cpp src/MarkerSubscriber.cpp)

target_include_directories(marker_pub_node PRIVATE include)
target_include_directories(marker_sub_node PRIVATE include)

ament_target_dependencies(marker_pub_node rclcpp visualization_msgs)
ament_target_dependencies(marker_sub_node rclcpp visualization_msgs)

# Add your test executable
ament_add_gtest(marker_pub_test test/test_publisher_node.cpp src/MarkerPublisher.cpp)
ament_target_dependencies(marker_pub_test rclcpp visualization_msgs)

target_include_directories(marker_pub_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


install(TARGETS 
        marker_pub_node
        marker_sub_node
        DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
        launch/
        DESTINATION share/${PROJECT_NAME}/launch
        )

install(DIRECTORY
        config/
        DESTINATION share/${PROJECT_NAME}/config
        )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()