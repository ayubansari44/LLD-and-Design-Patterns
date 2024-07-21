package com.educosys.observer;

public class User implements ISubscriber{
    private int userId;

    public User(int userId)
    {
        this.userId = userId;
    }

    public void notify(String msg)
    {
        System.out.println("User " + userId + " has been notified that " + msg);
    }

}
