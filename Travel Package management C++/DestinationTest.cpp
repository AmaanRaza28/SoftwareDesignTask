#include "Destination.h"
#include "Activity.h"
#include <gtest/gtest.h>
#include <memory>

TEST(DestinationTest, AddActivity) {
    auto destination = std::make_shared<Destination>("Paris");
    auto activity = std::make_shared<Activity>("Sightseeing", "Visit landmarks", 100, 15);

    EXPECT_TRUE(destination->addActivity(activity));

    EXPECT_TRUE(activity->isAssignedToDestination());

    EXPECT_FALSE(destination->addActivity(activity));
}

TEST(DestinationTest, AddSameActivityToDifferentDestinations) {
    auto destination1 = std::make_shared<Destination>("Bangalore");
    auto destination2 = std::make_shared<Destination>("Indore");
    auto activity = std::make_shared<Activity>("Sightseeing", "Visit landmarks", 100, 15);

    EXPECT_TRUE(destination1->addActivity(activity));
    
    EXPECT_FALSE(destination2->addActivity(activity));

   
    EXPECT_TRUE(activity->isAssignedToDestination());

    EXPECT_FALSE(destination1->addActivity(activity));
}