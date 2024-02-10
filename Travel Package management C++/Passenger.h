#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <memory>
#include <unordered_map>
#include <vector>
#include "Destination.h"
#include "Activity.h"

using namespace std;

class Passenger : public enable_shared_from_this<Passenger> {
private:
    string name;
    int passengerNumber;
    double balance;
    unordered_map<shared_ptr<Destination>, vector<shared_ptr<Activity>>> assignedActivities;
    

public:
    Passenger(string n, int passNum, double bal);
    virtual ~Passenger() {} 

    void printDetails();
    virtual double calculateActivityCost(shared_ptr<Activity> activity);

    string getName();
    int getPassengerNumber();

    virtual bool signUpForActivity(shared_ptr<Destination> destination, std::shared_ptr<Activity> activity) = 0;

    void deductBalance(double amount);

    double getBalance();
    void setBalance(double bal);
};

#endif // PASSENGER_H
