#include "Passenger.h"
#include <iostream>
#include "Activity.h"
#include "Destination.h"

using namespace std;

double Passenger::calculateActivityCost(shared_ptr<Activity> activity) {
    return activity->getCost();
}

Passenger::Passenger(string n, int passNum, double bal) : name(n), passengerNumber(passNum), balance(bal) {}

void Passenger::printDetails() {
    cout << "Passenger Name: " << name << ", Passenger Number: " << passengerNumber << ", Balance: " << balance << endl;
    for (const auto& pair : assignedActivities) {
        auto destination = pair.first;
        auto activities = pair.second;
        for (const auto& activity : activities) {
            cout << "Destination: " << destination->getName() << ", Activity: " << activity->getName() << ", Cost: $" << calculateActivityCost(activity) << endl;
        }
    }
}

string Passenger::getName() { return name; }
int Passenger::getPassengerNumber() { return passengerNumber; }

void Passenger::deductBalance(double amount) {
    balance -= amount;
}

double Passenger::getBalance() { return balance; }
void Passenger::setBalance(double bal) { balance = bal; }
