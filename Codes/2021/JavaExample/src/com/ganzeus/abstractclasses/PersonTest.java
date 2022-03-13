package com.ganzeus.abstractclasses;

public class PersonTest {
    public static void main(String[] args) {
        var people = new Person[2];

        people[0] = new Employee("Harry Hacker", 50000, 1980, 10, 1);
        people[1] = new Student("Maria Morris", "computer science");

        for (Person p : people)
            System.out.println(p.getName() + ", " + p.getDescription());
    }
}
