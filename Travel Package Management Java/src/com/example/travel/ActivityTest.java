package com.example.travel;

import org.junit.Test;
import static org.junit.Assert.*;

public class ActivityTest {

    @Test
    public void testConstructor() {
        Activity activity = new Activity("NightWalk", "Exploring the night life", 100, 15);
        assertEquals("NightWalk", activity.getName());
        assertEquals(100, activity.getCost(), 0.01); // The third parameter is delta for floating point comparisons
    }

    @Test
    public void testSignUp() {
        Activity activity = new Activity("Trekking", "Trekking the mountains", 50, 2);
        Passenger passenger1 = new StandardPassenger("Amaan", 1, 200);
        Passenger passenger2 = new StandardPassenger("Atif", 2, 200);
        assertTrue(activity.signUp(passenger1));
        assertTrue(activity.signUp(passenger2));
        Passenger passenger3 = new StandardPassenger("Aisha", 3, 200);
        assertFalse(activity.signUp(passenger3)); // Should be false since capacity is 2
    }
}

