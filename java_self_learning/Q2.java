package com.selflearning;

abstract class Shape {
	abstract void display();
}

abstract class Shape2D extends Shape {
	abstract double area();
}

abstract class Shape3D extends Shape {
	abstract double volume();
}

class Circle extends Shape2D {
	double radius;

	Circle(double radius) {
		this.radius = radius;
	}

	double area() {
		return Math.PI * radius * radius;
	}

	void display() {
		System.out.println("Circle Area: " + area());
	}
}

class Rectangle extends Shape2D {
	double length, width;

	Rectangle(double l, double w) {
		length = l;
		width = w;
	}

	double area() {
		return length * width;
	}

	void display() {
		System.out.println("Rectangle Area: " + area());
	}
}

class Sphere extends Shape3D {
	double radius;

	Sphere(double radius) {
		this.radius = radius;
	}

	double volume() {
		return (4.0 / 3) * Math.PI * Math.pow(radius, 3);
	}

	void display() {
		System.out.println("Sphere Volume: " + volume());
	}
}

class Cube extends Shape3D {
	double side;

	Cube(double side) {
		this.side = side;
	}

	double volume() {
		return Math.pow(side, 3);
	}

	void display() {
		System.out.println("Cube Volume: " + volume());
	}
}

public class Q2 {
	public static void main(String[] args) {
		Shape c = new Circle(5);
		Shape r = new Rectangle(4, 6);
		Shape s = new Sphere(3);
		Shape cu = new Cube(2);

		c.display();
		r.display();
		s.display();
		cu.display();
	}
}