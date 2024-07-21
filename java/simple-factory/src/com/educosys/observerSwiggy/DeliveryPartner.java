package com.educosys.observerSwiggy;

public class DeliveryPartner implements IObserver{
    private String name;

    public DeliveryPartner(String name){
        this.name = name;
    }

    public void notify(String msg)
    {
        System.out.println("DeliveryPartner "+ name + " has been notified that "+ msg);
    }
}
