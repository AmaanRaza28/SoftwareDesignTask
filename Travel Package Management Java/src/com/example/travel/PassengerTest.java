package com.example.travel;

import org.junit.Test;
import static org.junit.Assert.*;

public class PassengerTest {
    
    @Test
    public void testSignUpForActivity_StandardPassenger() {
        Destination bangalore = new Destination("Bangalore");
        Activity biking = new Activity("Biking", "Mountain biking", 50, 5);
        bangalore.addActivity(biking);

        StandardPassenger amaan = new StandardPassenger("Amaan", 1, 200);
        assertTrue(amaan.signUpForActivity(bangalore, biking));
        assertFalse(amaan.signUpForActivity(bangalore, biking)); // Already signed up
    }

    @Test
    public void testSignUpForActivity_GoldPassenger() {
        Destination bangalore = new Destination("Bangalore");
        Activity biking = new Activity("Biking", "Mountain biking", 50, 5);
        bangalore.addActivity(biking);

        GoldPassenger amaan = new GoldPassenger("Amaan", 1, 200);
        assertTrue(amaan.signUpForActivity(bangalore, biking)); // GoldPassenger signing up
        assertTrue(biking.isSignedUp(amaan)); // Confirm signup
    }

    @Test
    public void testActivityCost_GoldPassenger() {
        Activity biking = new Activity("Biking", "Mountain biking", 50, 5);
        GoldPassenger amaan = new GoldPassenger("Amaan", 1, 200);

        double expectedCost = 45.0; // Expecting a 10% discount
        assertEquals(expectedCost, amaan.calculateActivityCost(biking), 0.01);
    }

    @Test
    public void testSignUpForActivity_PremiumPassenger() {
        Destination bangalore = new Destination("Bangalore");
        Activity biking = new Activity("Biking", "Mountain biking", 50, 5);
        bangalore.addActivity(biking);

        PremiumPassenger amaan = new PremiumPassenger("Amaan", 1, 200);
        assertTrue(amaan.signUpForActivity(bangalore, biking)); // PremiumPassenger should sign up for free
        assertTrue(biking.isSignedUp(amaan)); // Confirm signup
    }

    @Test
    public void testActivityCost_PremiumPassenger() {
        Activity biking = new Activity("Biking", "Mountain biking", 50, 5);
        PremiumPassenger amaan = new PremiumPassenger("Amaan", 1, 200);

        double expectedCost = 0.0; // PremiumPassenger attends for free
        assertEquals(expectedCost, amaan.calculateActivityCost(biking), 0.01);
    }

   
}
