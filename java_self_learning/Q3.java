package com.selflearning;

class Food {
	String type;

	Food(String type) {
		this.type = type;
	}

	void displayFood() {
		System.out.println("Food: " + type);
	}
}

class Animal {
	String name;
	Food food;

	Animal(String name, Food food) {
		this.name = name;
		this.food = food;
	}

	void eat() {
		System.out.print(name + " eats ");
		food.displayFood();
	}

	void makeSound() {
		System.out.println("Animal makes sound");
	}
}

class Lion extends Animal {
	Lion(String name, Food food) {
		super(name, food);
	}

	void makeSound() {
		System.out.println(name + " roars");
	}
}

class Elephant extends Animal {
	Elephant(String name, Food food) {
		super(name, food);
	}

	void makeSound() {
		System.out.println(name + " trumpets");
	}
}

class Monkey extends Animal {
	Monkey(String name, Food food) {
		super(name, food);
	}

	void makeSound() {
		System.out.println(name + " chatters");
	}
}

class Zoo {
	Animal[] animals;
	int count = 0;

	Zoo(int size) {
		animals = new Animal[size];
	}

	void addAnimal(Animal a) {
		animals[count++] = a;
	}

	void showAnimals() {
		for (int i = 0; i < count; i++) {
			animals[i].makeSound();
			animals[i].eat();
			System.out.println();
		}
	}
}

public class Q3 {
	public static void main(String[] args) {
		Food meat = new Food("Meat");
		Food grass = new Food("Grass");
		Food fruits = new Food("Fruits");

		Animal lion = new Lion("Simba", meat);
		Animal elephant = new Elephant("Dumbo", grass);
		Animal monkey = new Monkey("Chintu", fruits);

		Zoo zoo = new Zoo(5);

		zoo.addAnimal(lion);
		zoo.addAnimal(elephant);
		zoo.addAnimal(monkey);

		zoo.showAnimals();
	}
}