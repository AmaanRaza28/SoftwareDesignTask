package com.example.travel;

public class GoldPassenger extends Passenger {
    public GoldPassenger(String name, int passengerNumber, double balance) {
        super(name, passengerNumber, balance);
    }

    @Override
    public boolean signUpForActivity(Destination destination, Activity activity) {
        double cost = calculateActivityCost(activity);
        if (getBalance() >= cost && !activity.isSignedUp(this)) {
            if (activity.signUp(this)) {
                deductBalance(cost);
                return true;
            }
        }
        return false;
    }

    @Override
    public double calculateActivityCost(Activity activity) {
        return activity.getCost() * 0.9;
    }
}
