#include "GoldPassenger.h"


using namespace std;


bool GoldPassenger::signUpForActivity(shared_ptr<Destination> destination, shared_ptr<Activity> activity){
    double cost = activity->getCost() * 0.9;
    if(getBalance() >= cost && !activity->isSignedUp(shared_from_this())){
        if(activity->signUp(shared_from_this())){
            deductBalance(cost);
            return true;
        }
    }
    return false;
} 

double GoldPassenger::calculateActivityCost(shared_ptr<Activity> activity){
    return activity->getCost() * 0.9; 
}   