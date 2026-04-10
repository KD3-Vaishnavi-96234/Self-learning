package com.selflearning;

import java.util.stream.IntStream;

public class Q8
{
    public static void main(String[] args) {
        int n = 5;

        int fact = IntStream.rangeClosed(1, n)
                            .reduce(1, (a, b) -> a * b);

        System.out.println("Factorial: " + fact);
    }
}