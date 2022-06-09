package com.ganzeus.stackTrace;

import java.util.*;

public class StackTraceTest {
    /**
     * Compute the factorial of a number
     *
     * @param n a non-negative integer
     * @return n! = 1 * 2 * ... * n
     */
    public static int factorial(int n) {
        System.out.println("factorial(" + n + "):");
        var walker = StackWalker.getInstance();
        walker.forEach(System.out::println);
        int r;
        if (n <= 1) r = 1;
        else r = n * factorial(n - 1);
        System.out.println("return " + r);
        return r;
    }

    public static void main(String[] args) {
        try (var in = new Scanner(System.in)) {   // try-with-resources
            System.out.println("Enter n: ");
            int n = in.nextInt();
            factorial(n);
        }
    }
}
