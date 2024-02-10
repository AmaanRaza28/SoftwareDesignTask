package com.example.travel;

import org.junit.Test;
import static org.junit.Assert.*;

public class TravelPackageTest {
    
    @Test
    public void testAddDestination() {
        TravelPackage adventureTrip = new TravelPackage("Adventure Trip", 10);
        Destination himalayas = new Destination("Himalayas");
        adventureTrip.addDestination(himalayas);

        assertEquals(1, adventureTrip.getItinerary().size());
        assertEquals("Himalayas", adventureTrip.getItinerary().get(0).getName());
    }

    @Test
    public void testAddPassenger() {
        TravelPackage adventureTrip = new TravelPackage("Adventure Trip", 10);
        Passenger amaan = new StandardPassenger("Amaan", 2, 300);
        adventureTrip.addPassenger(amaan);

        assertEquals(1, adventureTrip.getPassengerList().size());
        assertEquals("Amaan", adventureTrip.getPassengerList().get(0).getName());
    }
}
