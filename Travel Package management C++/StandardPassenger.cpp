#include "StandardPassenger.h"

using namespace std;

bool StandardPassenger::signUpForActivity(shared_ptr<Destination> destination, shared_ptr<Activity> activity){
    double cost = activity->getCost();
    if(this->getBalance() >= cost && !activity->isSignedUp(this->shared_from_this())){
        if(activity->signUp(this->shared_from_this())){
            this->deductBalance(cost);
            return true;
        }
    }
    return false;
}
