#ifndef GOLDPASSENGER_H
#define GOLDPASSENGER_H

#include "Passenger.h"
#include "Activity.h"
#include "Destination.h"

using namespace std;


class GoldPassenger : public Passenger {
public:
    using Passenger::Passenger;

    bool signUpForActivity(shared_ptr<Destination> destination, shared_ptr<Activity> activity) override;

    double calculateActivityCost(shared_ptr<Activity> activity) override;
};

#endif // GOLDPASSENGER_H