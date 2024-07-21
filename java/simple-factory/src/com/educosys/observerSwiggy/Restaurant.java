package com.educosys.observerSwiggy;

public class Restaurant implements IObserver{
    private String name;

    public Restaurant(String name){
        this.name = name;
    }

    public void notify(String msg)
    {
        System.out.println("Restaurant "+ name + " has been notified that "+ msg);
    }
}
