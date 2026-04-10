package com.selflearning;

import java.util.*;


class Product {
	int id;
	String name;
	double price;

	Product(int id, String name, double price) {
		this.id = id;
		this.name = name;
		this.price = price;
	}
}

class ShoppingCart {
	HashMap<Product, Integer> cart = new HashMap<>();

	void addProduct(Product p, int quantity) {
		cart.put(p, cart.getOrDefault(p, 0) + quantity);
		System.out.println(p.name + " added to cart.");
	}

	void removeProduct(Product p) {
		cart.remove(p);
		System.out.println(p.name + " removed from cart.");
	}

	void showCart() {
		double total = 0;
		System.out.println("\nCart Items:");
		for (Map.Entry<Product, Integer> entry : cart.entrySet()) {
			Product p = entry.getKey();
			int qty = entry.getValue();
			double cost = p.price * qty;

			System.out.println(p.name + " x " + qty + " = " + cost);
			total += cost;
		}
		System.out.println("Total: " + total);
	}

	Order checkout() {
		Order order = new Order(new HashMap<>(cart));
		cart.clear();
		return order;
	}
}

class Order {
	HashMap<Product, Integer> items;
	Date date;

	Order(HashMap<Product, Integer> items) {
		this.items = items;
		this.date = new Date();
	}

	void showOrder() {
		System.out.println("\nOrder Date: " + date);
		double total = 0;

		for (Map.Entry<Product, Integer> entry : items.entrySet()) {
			Product p = entry.getKey();
			int qty = entry.getValue();
			double cost = p.price * qty;

			System.out.println(p.name + " x " + qty + " = " + cost);
			total += cost;
		}
		System.out.println("Order Total: " + total);
	}
}

public class Q7 {
	public static void main(String[] args) {

		Product p1 = new Product(1, "Laptop", 50000);
		Product p2 = new Product(2, "Phone", 20000);
		Product p3 = new Product(3, "Headphones", 2000);

		ShoppingCart cart = new ShoppingCart();
		ArrayList<Order> orderHistory = new ArrayList<>();

		cart.addProduct(p1, 1);
		cart.addProduct(p2, 2);
		cart.addProduct(p3, 3);

		cart.showCart();

		Order order1 = cart.checkout();
		orderHistory.add(order1);

		System.out.println("\nOrder History:");
		for (Order o : orderHistory) {
			o.showOrder();
		}
	}
}