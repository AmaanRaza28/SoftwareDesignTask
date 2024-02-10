#include "Destination.h"
#include "Activity.h"
#include <iostream>

using namespace std;  



Destination::Destination(string n){
    name = n;
}


bool Destination::addActivity(shared_ptr<Activity> activity) {
    if (activity->isAssignedToDestination()) {
        return false;
    }
    activity->assignToDestination(name); 
    activities.push_back(activity); 
    return true;
}

void Destination::printDetails(){
    cout << "Destination name: " << name << endl;
    cout << "Activities: " << endl;
    for(const auto& activity : activities){
        activity->printDetails();
    }
}

void Destination::printAvailableActivities(){
    cout << "Destination: " << name << endl;
    cout << "Available activities: " << endl;
    for(const auto& activity : activities){
        if(activity->isAvailable()){
            activity->printAvailableActivityDetails();
        }
    }
}

string Destination::getName(){ return name; }