#ifndef DESTINATION_H
#define DESTINATION_H

#include <string>
#include <memory>
#include <vector>


using namespace std;

class Activity;


class Destination{
private:
    string name;
    vector<shared_ptr<Activity>> activities;

public:
    Destination(string n);

    bool addActivity(shared_ptr<Activity> activity);

    void printDetails();

    void printAvailableActivities();

    string getName();

};

#endif // DESTINATION_H