package com.selflearning;

public class Q11 {

	public static <T extends Number & Comparable<T>> T findMin(T[] arr) {
		T min = arr[0];

		for (T val : arr) {
			if (val.compareTo(min) < 0) {
				min = val;
			}
		}
		return min;
	}

	public static void main(String[] args) {
		Integer[] arr = { 5, 2, 9, 1, 3 };
		System.out.println("Min: " + findMin(arr));
	}
}
