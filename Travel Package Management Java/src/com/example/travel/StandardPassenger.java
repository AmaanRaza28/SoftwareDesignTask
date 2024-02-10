package com.example.travel;

public class StandardPassenger extends Passenger {
    public StandardPassenger(String name, int passengerNumber, double balance) {
        super(name, passengerNumber, balance);
    }

    @Override
    public boolean signUpForActivity(Destination destination, Activity activity) {
        double cost = activity.getCost();
        if (getBalance() >= cost && !activity.isSignedUp(this)) {
            if (activity.signUp(this)) {
                deductBalance(cost);
                return true;
            }
        }
        return false;
    }
}
