package com.selflearning;

class EcommerceException extends Exception {
	public EcommerceException(String message) {
		super(message);
	}
}

class PaymentException extends EcommerceException {
	public PaymentException(String message) {
		super(message);
	}
}

class InsufficientFundsException extends PaymentException {
	public InsufficientFundsException(String message) {
		super(message);
	}
}

class InvalidPaymentMethodException extends PaymentException {
	public InvalidPaymentMethodException(String message) {
		super(message);
	}
}

class InventoryException extends EcommerceException {
	public InventoryException(String message) {
		super(message);
	}
}

class OutOfStockException extends InventoryException {
	public OutOfStockException(String message) {
		super(message);
	}
}

class ShippingException extends EcommerceException {
	public ShippingException(String message) {
		super(message);
	}
}

class InvalidAddressException extends ShippingException {
	public InvalidAddressException(String message) {
		super(message);
	}
}

class OrderService {

	public static void processPayment(double balance, double amount, String method) throws PaymentException {

		if (!method.equalsIgnoreCase("CARD") && !method.equalsIgnoreCase("UPI")) {
			throw new InvalidPaymentMethodException("Invalid payment method!");
		}

		if (balance < amount) {
			throw new InsufficientFundsException("Insufficient balance!");
		}

		System.out.println("Payment successful.");
	}

	public static void checkInventory(int stock) throws InventoryException {

		if (stock <= 0) {
			throw new OutOfStockException("Product is out of stock!");
		}

		System.out.println("Product available.");
	}

	public static void validateAddress(String address) throws ShippingException {

		if (address == null || address.trim().isEmpty()) {
			throw new InvalidAddressException("Invalid shipping address!");
		}

		System.out.println("Address validated.");
	}
}

class Q6 {
	public static void main(String[] args) {

		try {
			OrderService.processPayment(5000, 6000, "CARD");

			OrderService.checkInventory(0);

			OrderService.validateAddress("");

		} catch (PaymentException e) {
			System.out.println("Payment Error: " + e.getMessage());

		} catch (InventoryException e) {
			System.out.println("Inventory Error: " + e.getMessage());

		} catch (ShippingException e) {
			System.out.println("Shipping Error: " + e.getMessage());

		} catch (EcommerceException e) {
			System.out.println("General Error: " + e.getMessage());
		}

		System.out.println("Application Ended.");
	}
}