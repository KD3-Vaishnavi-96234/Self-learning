package com.selflearning;

import java.util.stream.IntStream;
import java.util.IntSummaryStatistics;

public class Q10 {
	public static void main(String[] args) {

		IntStream stream = IntStream.rangeClosed(1, 10);

		int sum = stream.sum();
		System.out.println("Sum: " + sum);

		IntSummaryStatistics stats = IntStream.rangeClosed(1, 10).summaryStatistics();

		System.out.println("Count: " + stats.getCount());
		System.out.println("Min: " + stats.getMin());
		System.out.println("Max: " + stats.getMax());
		System.out.println("Average: " + stats.getAverage());
	}
}