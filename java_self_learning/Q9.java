package com.selflearning;

import java.util.*;

public class Q9 {
    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(10, 20, 30, 40);

        int sum = list.stream()
                      .mapToInt(Integer::intValue)
                      .sum();

        System.out.println("Sum: " + sum);
    }
}