#ifndef TRAVELPACKAGE_H
#define TRAVELPACKAGE_H

#include <string>
#include <memory>
#include <vector>
#include "Destination.h" 
#include "Passenger.h"  

using namespace std;

class TravelPackage {
private:
    string name;
    int capacity;
    vector<shared_ptr<Destination>> itinerary;
    vector<shared_ptr<Passenger>> passengerList;

public:
    TravelPackage(string n, int cap);
    void addDestination(shared_ptr<Destination> destination);
    void addPassenger(shared_ptr<Passenger> passenger);
    void printItinerary();
    void printPassengerList();
    void printAvailableActivities();

    vector<shared_ptr<Destination>> getItinerary();
    vector<shared_ptr<Passenger>> getPassengerList();
};

#endif // TRAVELPACKAGE_H
