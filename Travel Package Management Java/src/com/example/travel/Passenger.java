package com.example.travel;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public abstract class Passenger {
    private String name;
    private int passengerNumber;
    private double balance;
    private Map<Destination, List<Activity>> assignedActivities = new HashMap<>();

    public Passenger(String name, int passengerNumber, double balance) {
        this.name = name;
        this.passengerNumber = passengerNumber;
        this.balance = balance;
    }

    public void printDetails() {
        System.out.println("Passenger Name: " + name + ", Passenger Number: " + passengerNumber + ", Balance: " + balance);
        for (Map.Entry<Destination, List<Activity>> entry : assignedActivities.entrySet()) {
            Destination destination = entry.getKey();
            List<Activity> activities = entry.getValue();
            for (Activity activity : activities) {
                System.out.println("Destination: " + destination.getName() + ", Activity: " + activity.getName() + ", Cost: $" + calculateActivityCost(activity));
            }
        }
    }

    public double calculateActivityCost(Activity activity) {
        return activity.getCost();
    }

    public abstract boolean signUpForActivity(Destination destination, Activity activity);

    public void deductBalance(double amount) {
        balance -= amount;
    }

    public String getName() {
        return name;
    }

    public int getPassengerNumber() {
        return passengerNumber;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }
}
