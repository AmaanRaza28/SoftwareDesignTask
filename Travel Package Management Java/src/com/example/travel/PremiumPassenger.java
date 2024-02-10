package com.example.travel;

public class PremiumPassenger extends Passenger {
    public PremiumPassenger(String name, int passengerNumber, double balance) {
        super(name, passengerNumber, balance);
    }

    @Override
    public boolean signUpForActivity(Destination destination, Activity activity) {
        if (!activity.isSignedUp(this)) {
            return activity.signUp(this);
        }
        return false;
    }

    @Override
    public double calculateActivityCost(Activity activity) {
        return 0.0; // Free for PremiumPassenger
    }
}
