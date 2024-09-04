#include "gtest/gtest.h"
#include "ros2_simple/MarkerPublisher.hpp"

class MarkerPublisherTest: public ::testing::Test {
protected:
    void SetUp() override {
        rclcpp::init(0, nullptr);
        _node = std::make_shared<ros2_simple::MarkerPublisher>();
    }

    void TearDown() override {
        rclcpp::shutdown();
    }

    std::shared_ptr<ros2_simple::MarkerPublisher> _node;
};


// Test case for the process_data method
TEST_F(MarkerPublisherTest, updateMarkerTest1){
    // Pre-condition: x-position should be 0.25
    EXPECT_EQ(_node->getMarker().pose.position.x, 0.25);

    // Set some parameters
    _node->setFrequency(10);
    _node->setSpeed(0.1);

    // Call the update method
    _node->updateMarker();

    // Post-condition: x-position should be 0.26
    EXPECT_EQ(_node->getMarker().pose.position.x, 0.26);

    // Call the update method again
    _node->updateMarker();

    // Post-condition: x-position should be 0.27
    EXPECT_EQ(_node->getMarker().pose.position.x, 0.27);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


