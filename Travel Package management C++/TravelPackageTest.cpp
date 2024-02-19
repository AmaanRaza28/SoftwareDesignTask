#include "TravelPackage.h"
#include "Destination.h"
#include "Passenger.h"
#include "StandardPassenger.h"
#include "Activity.h"
#include <gtest/gtest.h>
#include <memory>

TEST(TravelPackageTest, AddDestination) {
    auto travelPackage = std::make_shared<TravelPackage>("Adventure Trip", 10);
    auto destination = std::make_shared<Destination>("Himalayas");
    travelPackage->addDestination(destination);

    auto itinerary = travelPackage->getItinerary();

    EXPECT_EQ(itinerary.size(), 1);

    EXPECT_EQ(itinerary.front()->getName(), "Himalayas");
}


TEST(TravelPackageTest, AddPassenger_Success) {
    auto travelPackage = std::make_shared<TravelPackage>("Adventure Trip", 10);
    auto passenger = std::make_shared<StandardPassenger>("Amaan", 2, 300);
    travelPackage->addPassenger(passenger);

    auto passengerList = travelPackage->getPassengerList();

    EXPECT_EQ(passengerList.size(), 1);

    EXPECT_EQ(passengerList.front()->getName(), "Amaan");
}
