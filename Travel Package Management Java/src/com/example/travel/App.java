package com.example.travel;

public class App {
    public static void main(String[] args) {
        Destination paris = new Destination("Paris");
        Destination newYork = new Destination("New York");

        Activity eiffelTowerTour = new Activity("Eiffel Tower Tour", "Visit the iconic Eiffel Tower", 120, 20);
        Activity statueOfLibertyTour = new Activity("Statue of Liberty Tour", "Tour the Statue of Liberty", 100, 15);

        paris.addActivity(eiffelTowerTour);
        newYork.addActivity(statueOfLibertyTour);

        TravelPackage europeanAdventure = new TravelPackage("European Adventure", 5);
        europeanAdventure.addDestination(paris);
        europeanAdventure.addDestination(newYork);

        StandardPassenger amaan = new StandardPassenger("Amaan", 1, 500);
        GoldPassenger atif = new GoldPassenger("Atif", 2, 1000);
        PremiumPassenger aisha = new PremiumPassenger("Aisha", 3, 2000);

        europeanAdventure.addPassenger(amaan);
        europeanAdventure.addPassenger(atif);
        europeanAdventure.addPassenger(aisha);

        amaan.signUpForActivity(paris, eiffelTowerTour);
        atif.signUpForActivity(newYork, statueOfLibertyTour);
        aisha.signUpForActivity(paris, eiffelTowerTour);

        System.out.println("Travel Package Details:");
        europeanAdventure.printItinerary();
        europeanAdventure.printPassengerList();

        System.out.println("\nAvailable Activities:");
        paris.printAvailableActivities();
        newYork.printAvailableActivities();
    }
}
