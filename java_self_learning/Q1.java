package com.selflearning;

class Students {
	int id;
	String name;
	String city;

	Students() {

	}

	Students(int id, String name, String city) {
		this.id = id;
		this.name = name;
		this.city = city;
	}

	Students deepCopy() {
		return new Students(this.id, this.name, this.city);
	}

	void display() {
		System.out.println(id + " " + name + " " + city);
	}
}

public class Q1 {
	public static void main(String[] args) {
		Students s1 = new Students(1, "Amit", "pune");

		Students shallow = s1;
		Students deep = s1.deepCopy();

		s1.city = "Mumbai";

		s1.display();
		shallow.display();
		deep.display();
	}
}