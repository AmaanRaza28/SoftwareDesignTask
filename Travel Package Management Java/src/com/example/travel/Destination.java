package com.example.travel;

import java.util.ArrayList;
import java.util.List;

public class Destination {
    private String name;
    private List<Activity> activities = new ArrayList<>();

    public Destination(String name) {
        this.name = name;
    }

    public boolean addActivity(Activity activity) {
        if (activity.isAssignedToDestination()) {
            return false;
        }
        activity.assignToDestination(name);
        activities.add(activity);
        return true;
    }

    public void printDetails() {
        System.out.println("Destination name: " + name);
        System.out.println("Activities: ");
        for (Activity activity : activities) {
            activity.printDetails();
        }
    }

    public void printAvailableActivities() {
        System.out.println("Destination: " + name);
        System.out.println("Available activities: ");
        for (Activity activity : activities) {
            if (activity.isAvailable()) {
                activity.printAvailableActivityDetails();
            }
        }
    }

    public String getName() {
        return name;
    }
}
