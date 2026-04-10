package com.selflearning;

enum Day {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY;

    public boolean isWeekend() {
        return this == SATURDAY || this == SUNDAY;
    }

    public boolean isWeekday() {
        return !isWeekend();
    }
}

public class Q4 {
    public static void main(String[] args) {
        Day today = Day.SATURDAY;

        System.out.println("Today: " + today);

        if (today.isWeekend()) {
            System.out.println("It's a weekend!");
        } else {
            System.out.println("It's a weekday.");
        }

        for (Day d : Day.values()) {
            System.out.println(d + " -> Weekend? " + d.isWeekend());
        }
    }
}