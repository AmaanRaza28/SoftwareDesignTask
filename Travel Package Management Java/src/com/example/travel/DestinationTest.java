package com.example.travel;

import org.junit.Test;
import static org.junit.Assert.*;

public class DestinationTest {
    
    @Test
    public void testAddActivity() {
        Destination paris = new Destination("Paris");
        Activity sightseeing = new Activity("Sightseeing", "Visit landmarks", 100, 15);

        assertTrue(paris.addActivity(sightseeing));
        assertTrue(sightseeing.isAssignedToDestination());
        assertFalse(paris.addActivity(sightseeing)); // Activity already assigned, should return false
    }

    @Test
    public void testAddSameActivityToDifferentDestinations() {
        Destination bangalore = new Destination("Bangalore");
        Destination indore = new Destination("Indore");
        Activity sightseeing = new Activity("Sightseeing", "Visit landmarks", 100, 15);

        assertTrue(bangalore.addActivity(sightseeing));
        assertFalse(indore.addActivity(sightseeing)); // Activity can't be assigned to two destinations
    }
}
