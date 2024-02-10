#ifndef STANDARDPASSENGER_H
#define STANDARDPASSENGER_H

#include "Passenger.h"
#include "Activity.h"
#include "Destination.h"

using namespace std;


class StandardPassenger : public Passenger {
public:
    using Passenger::Passenger;

    bool signUpForActivity(shared_ptr<Destination> destination, shared_ptr<Activity> activity) override; 
};

#endif // STANDARPASSENGER_H