package com.example.travel;

import java.util.ArrayList;
import java.util.List;

public class TravelPackage {
    private String name;
    private int capacity;
    private List<Destination> itinerary = new ArrayList<>();
    private List<Passenger> passengerList = new ArrayList<>();

    public TravelPackage(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
    }

    public void addDestination(Destination destination) {
        itinerary.add(destination);
    }

    public void addPassenger(Passenger passenger) {
        if (passengerList.size() < capacity) {
            passengerList.add(passenger);
        } else {
            System.out.println("Cannot add more passengers, capacity reached.");
        }
    }

    public void printItinerary() {
        System.out.println("Travel Package Name: " + name);
        System.out.println("Destinations:");
        for (Destination destination : itinerary) {
            destination.printDetails();
            System.out.println();
        }
    }

    public void printPassengerList() {
        System.out.println("Travel Package Name: " + name);
        System.out.println("Passenger Capacity: " + capacity);
        System.out.println("Passengers currently enrolled: " + passengerList.size());
        for (Passenger passenger : passengerList) {
            System.out.println("Passenger Name: " + passenger.getName() + ", Passenger Number: " + passenger.getPassengerNumber());
        }
    }

    public void printAvailableActivities() {
        for (Destination destination : itinerary) {
            destination.printAvailableActivities();
        }
    }

    public List<Destination> getItinerary() {
        return itinerary;
    }

    public List<Passenger> getPassengerList() {
        return passengerList;
    }
}
