package com.educosys.observerSwiggy;

public class Main {
    public static void main(String args[])
    {
        Customer cus1 = new Customer("Raaj");
        Restaurant res1 = new Restaurant("Hotel Taaj");
        DeliveryPartner del1 = new DeliveryPartner("Driver Peter");

        Order ord1 = new Order();
        ord1.subscribe(cus1);
        ord1.subscribe(res1);
        ord1.notifyAll("Order has been placed!");

        ord1.subscribe(del1);
        ord1.notifyAll("Order is ready for pick up");

        ord1.unsubscribe(res1);

        ord1.notifyAll("Order has been delivered!");

    }
}
