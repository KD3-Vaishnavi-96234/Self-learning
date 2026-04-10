package com.selflearning;

import java.util.*;

class Learner {
	private int roll;
	private String name;
	private String city;
	private double marks;

	public Learner(int roll, String name, String city, double marks) {
		this.roll = roll;
		this.name = name;
		this.city = city;
		this.marks = marks;
	}

	public String getName() {
		return name;
	}

	public String getCity() {
		return city;
	}

	public double getMarks() {
		return marks;
	}

	@Override
	public String toString() {
		return roll + " " + name + " " + city + " " + marks;
	}
}

public class Q13 {
	public static void main(String[] args) {
		Learner[] students = { new Learner(1, "Amit", "Pune", 85.5), new Learner(2, "Ravi", "Mumbai", 90.0),
				new Learner(3, "Sneha", "Pune", 90.0), new Learner(4, "Kiran", "Mumbai", 88.0),
				new Learner(5, "Anita", "Pune", 85.5) };

		Arrays.sort(students, new Comparator<Learner>() {
			@Override
			public int compare(Learner s1, Learner s2) {

				int cityCompare = s2.getCity().compareTo(s1.getCity());
				if (cityCompare != 0)
					return cityCompare;

				int marksCompare = Double.compare(s2.getMarks(), s1.getMarks());
				if (marksCompare != 0)
					return marksCompare;

				return s1.getName().compareTo(s2.getName());
			}
		});

		for (Learner s : students) {
			System.out.println(s);
		}
	}
}