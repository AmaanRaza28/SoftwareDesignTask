#include "TravelPackage.h"
#include "Destination.h"
#include "Passenger.h"
#include <iostream>


TravelPackage::TravelPackage(string n, int cap){
    name = n;
    capacity = cap;
}

void TravelPackage::addDestination(shared_ptr<Destination> destination){
    itinerary.push_back(destination);
}

void TravelPackage::addPassenger(shared_ptr<Passenger> passenger){
    passengerList.push_back(passenger);
}

void TravelPackage::printItinerary() {
    cout << "Travel Package Name: " << name << endl;
    cout << "Destinations:" << endl;
    for (const auto& destination : itinerary) {
        destination->printDetails();
        cout << endl; 
    }
}

void TravelPackage::printPassengerList() {
    cout << "Travel Package Name: " << name << endl;
    cout << "Passenger Capacity: " << capacity << endl;
    cout << "Passengers currently enrolled: " << passengerList.size() << endl;
    for(const auto& passenger : passengerList){
        cout << "Passenger Name: " << passenger->getName() << ", Passenger Number: " << passenger->getPassengerNumber();
    }
}

void TravelPackage::printAvailableActivities(){
    for(const auto& destination : itinerary){
        destination->printAvailableActivities();
    }
}

vector<shared_ptr<Destination>> TravelPackage::getItinerary(){ return itinerary; }
vector<shared_ptr<Passenger>> TravelPackage::getPassengerList(){ return passengerList; }
