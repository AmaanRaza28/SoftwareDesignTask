#include "Activity.h"
#include "Passenger.h" 
#include <iostream>

using namespace std;


Activity::Activity(string n, string desc, int c, int cap){
    name = n;
    description = desc;
    cost = c;
    capacity = cap;
}

void Activity::printDetails(){
    cout << "Activity name: " << name << ", Description: " << description << ", Cost: " << cost << ", Capacity: " << capacity << endl;
}
double Activity::getCost(){ return cost; }
string Activity::getName(){ return name; }

void Activity::assignToDestination(string destination){
    assignedDestination = destination;
    assigned = true;
}

bool Activity::isAssignedToDestination(){
    return assigned;
}

bool Activity::signUp(shared_ptr<Passenger> passenger){
    if(signedUpPassengers.size() >= capacity)return false;
    return signedUpPassengers.insert(passenger).second;
}

bool Activity::isSignedUp(shared_ptr<Passenger> passenger){
    return signedUpPassengers.find(passenger) != signedUpPassengers.end();
}

bool Activity::isAvailable(){ return signedUpPassengers.size() < capacity; }

void Activity::printAvailableActivityDetails(){
    cout << "Activity Name: " << name << ", Spaces Available: " << (capacity - signedUpPassengers.size()) << endl;
}

