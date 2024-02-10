#include "Passenger.h"
#include "StandardPassenger.h"
#include "GoldPassenger.h"
#include "PremiumPassenger.h"
#include "Activity.h"
#include <gtest/gtest.h>
#include <memory>


TEST(StandardPassengerTest, SignUpForActivity) {
    auto passenger = std::make_shared<StandardPassenger>("Amaan", 1, 200);
    auto destination = std::make_shared<Destination>("Bangalore");
    auto activity1 = std::make_shared<Activity>("Biking", "Mountain biking", 50, 5);
    auto activity2 = std::make_shared<Activity>("Safari", "Jungle Safari", 500, 5);

    destination->addActivity(activity1);
    destination->addActivity(activity2);

    EXPECT_TRUE(passenger->signUpForActivity(destination, activity1));
    EXPECT_FALSE(passenger->signUpForActivity(destination, activity2));
}

TEST(PremiumPassengerTest, SignUpForActivity) {
    auto passenger = std::make_shared<PremiumPassenger>("Amaan", 1, 200);
    auto destination = std::make_shared<Destination>("Bangalore");
    auto activity1 = std::make_shared<Activity>("Biking", "Mountain biking", 50, 5);
    auto activity2 = std::make_shared<Activity>("Safari", "Jungle Safari", 500, 5);

    destination->addActivity(activity1);
    destination->addActivity(activity2);

    EXPECT_TRUE(passenger->signUpForActivity(destination, activity1));
    EXPECT_TRUE(passenger->signUpForActivity(destination, activity2));
}

TEST(GoldPassengerTest, ActivityCost) {
    auto passenger = std::make_shared<GoldPassenger>("Amaan", 1, 200);
    auto destination = std::make_shared<Destination>("Bangalore");
    auto activity1 = std::make_shared<Activity>("Biking", "Mountain biking", 50, 5);

    destination->addActivity(activity1);

    passenger->signUpForActivity(destination, activity1);

    EXPECT_EQ(passenger->calculateActivityCost(activity1), 45);
}

TEST(PremiumPassengerTest, ActivityCost) {
    auto passenger = std::make_shared<PremiumPassenger>("Amaan", 1, 200);
    auto destination = std::make_shared<Destination>("Bangalore");
    auto activity1 = std::make_shared<Activity>("Biking", "Mountain biking", 50, 5);

    destination->addActivity(activity1);

    passenger->signUpForActivity(destination, activity1);

    EXPECT_EQ(passenger->calculateActivityCost(activity1), 0);
}

TEST(StandardPassengerTest, ActivityCost) {
    auto passenger = std::make_shared<StandardPassenger>("Amaan", 1, 200);
    auto destination = std::make_shared<Destination>("Bangalore");
    auto activity1 = std::make_shared<Activity>("Biking", "Mountain biking", 50, 5);

    destination->addActivity(activity1);

    passenger->signUpForActivity(destination, activity1);

    EXPECT_EQ(passenger->calculateActivityCost(activity1), 50);
}
