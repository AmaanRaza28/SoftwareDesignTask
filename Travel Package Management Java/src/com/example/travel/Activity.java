package com.example.travel;

import java.util.HashSet;
import java.util.Set;

public class Activity {
    private String name;
    private String description;
    private int cost;
    private int capacity;
    private String assignedDestination;
    private boolean assigned = false;
    private Set<Passenger> signedUpPassengers = new HashSet<>();

    public Activity(String name, String description, int cost, int capacity) {
        this.name = name;
        this.description = description;
        this.cost = cost;
        this.capacity = capacity;
    }

    public void printDetails() {
        System.out.println("Activity name: " + name + ", Description: " + description + ", Cost: " + cost + ", Capacity: " + capacity);
    }

    public double getCost() {
        return cost;
    }

    public String getName() {
        return name;
    }

    public void assignToDestination(String destination) {
        this.assignedDestination = destination;
        this.assigned = true;
    }

    public boolean isAssignedToDestination() {
        return assigned;
    }

    public boolean signUp(Passenger passenger) {
        if (signedUpPassengers.size() >= capacity) return false;
        return signedUpPassengers.add(passenger);
    }

    public boolean isSignedUp(Passenger passenger) {
        return signedUpPassengers.contains(passenger);
    }

    public boolean isAvailable() {
        return signedUpPassengers.size() < capacity;
    }

    public void printAvailableActivityDetails() {
        System.out.println("Activity Name: " + name + ", Spaces Available: " + (capacity - signedUpPassengers.size()));
    }
}
