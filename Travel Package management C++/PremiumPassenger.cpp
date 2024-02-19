#include "PremiumPassenger.h"
#include "Activity.h"
#include "Destination.h"

using namespace std;


bool PremiumPassenger::signUpForActivity(shared_ptr<Destination> destination, shared_ptr<Activity> activity){
    if(!activity->isSignedUp(shared_from_this())){
        return activity->signUp(shared_from_this());
    }
    return false;
} 

double PremiumPassenger::calculateActivityCost(shared_ptr<Activity> activity){
    return 0.0;
}   
