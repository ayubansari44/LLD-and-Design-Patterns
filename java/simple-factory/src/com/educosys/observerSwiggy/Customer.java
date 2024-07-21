package com.educosys.observerSwiggy;

public class Customer implements IObserver{
    private String name;

    public Customer(String name){
        this.name = name;
    }

    public void notify(String msg)
    {
        System.out.println("Customer "+ name + " has been notified that "+ msg);
    }
}
