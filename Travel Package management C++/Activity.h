// Activity.h
#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <memory>
#include <unordered_set>
#include <vector>

using namespace std;

class Passenger; // Forward declaration

class Activity {
private:
    string name;
    string description;
    int cost;
    int capacity;
    string assignedDestination;
    bool assigned = false;
    unordered_set<shared_ptr<Passenger>> signedUpPassengers;

public:
    Activity(string n, string desc, int c, int cap);
    void printDetails();
    double getCost();
    string getName();
    void assignToDestination(string destination);
    bool isAssignedToDestination();
    bool signUp(shared_ptr<Passenger> passenger);
    bool isSignedUp(shared_ptr<Passenger> passenger);
    bool isAvailable();
    void printAvailableActivityDetails();
};

#endif // ACTIVITY_H
