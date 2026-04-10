package com.selflearning;

import java.util.Scanner;

public class Q5 {

	public static void analyzeText(String text) {
		int vowels = 0, consonants = 0, digits = 0, spaces = 0, specialChars = 0;

		text = text.toLowerCase();

		for (int i = 0; i < text.length(); i++) {
			char ch = text.charAt(i);

			if (ch >= 'a' && ch <= 'z') {
				if ("aeiou".indexOf(ch) != -1)
					vowels++;
				else
					consonants++;
			} else if (ch >= '0' && ch <= '9') {
				digits++;
			} else if (ch == ' ') {
				spaces++;
			} else {
				specialChars++;
			}
		}

		int totalChars = text.length();
		int letters = vowels + consonants;

		System.out.println("Text Analysis Report");
		System.out.println("--------------------");
		System.out.println("Total Characters: " + totalChars);
		System.out.println("Letters: " + letters);
		System.out.println("Vowels: " + vowels);
		System.out.println("Consonants: " + consonants);
		System.out.println("Digits: " + digits);
		System.out.println("Spaces: " + spaces);
		System.out.println("Special Characters: " + specialChars);

		System.out.println("\nStatistics:");
		System.out.printf("Vowels %%: %.2f\n", (vowels * 100.0) / totalChars);
		System.out.printf("Consonants %%: %.2f\n", (consonants * 100.0) / totalChars);
		System.out.printf("Digits %%: %.2f\n", (digits * 100.0) / totalChars);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter text: ");
		String input = sc.nextLine();

		analyzeText(input);
	}
}