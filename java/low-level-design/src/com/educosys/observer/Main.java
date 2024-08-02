package com.educosys.observer;

public class Main {
    public static void main(String args[])
    {
        User user1 = new User(1);
        User user2 = new User(2);
        User user3 = new User(3);

        Group g1 = new Group();

        g1.subscribe(user1);
        g1.subscribe(user2);
        g1.subscribe(user3);
        g1.notify("You are selected");

        g1.unsubscribe(user2);
        g1.notify("Check again");
    }
}
