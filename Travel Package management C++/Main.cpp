#include<bits/stdc++.h>
#include "TravelPackage.h"
#include "Destination.h"
#include "Passenger.h"
#include "GoldPassenger.h"
#include "StandardPassenger.h"
#include "PremiumPassenger.h"
#include "Activity.h"


using namespace std;



int main() {
    #ifndef ONLINE_JUDG
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto tp = make_shared<TravelPackage>("Holiday Escape", 30);
    auto paris = make_shared<Destination>("Paris");
    auto newyork = make_shared<Destination>("New York");

    auto sightseeing = make_shared<Activity>("Sightseeing", "Visit landmarks", 100, 15);

    if(paris->addActivity(sightseeing)) {
        cout << "Added to Paris" << endl;
    } else {
        cout << "Failed to add to Paris" << endl;
    }

    if(newyork->addActivity(sightseeing)) {
        cout << "Added to New York" << endl;
    } else {
        cout << "Failed to add to New York" << endl;
    }

    tp->addDestination(paris); 
    tp->printItinerary();
}
