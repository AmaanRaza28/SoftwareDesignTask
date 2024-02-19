#include "Activity.h"
#include "StandardPassenger.h" 
#include <gtest/gtest.h>
#include <memory>

TEST(ActivityTest, Constructor) {
    Activity activity("NightWalk", "Exploring the night life", 100, 15);
    EXPECT_EQ(activity.getName(), "NightWalk");
    EXPECT_EQ(activity.getCost(), 100);
}

// Test the signUp function for capacity limits
TEST(ActivityTest, SignUp) {
    Activity activity("Trekking", "Trekking the mountains", 50, 2);
    auto passenger1 = std::make_shared<StandardPassenger>("Amaan", 1, 200); // Use StandardPassenger
    auto passenger2 = std::make_shared<StandardPassenger>("Atif", 2, 200); // Use StandardPassenger
    EXPECT_TRUE(activity.signUp(passenger1));
    EXPECT_TRUE(activity.signUp(passenger2));
    auto passenger3 = std::make_shared<StandardPassenger>("Aisha", 3, 200); // Use StandardPassenger
    EXPECT_FALSE(activity.signUp(passenger3)); // Should be false since capacity is 2
}
