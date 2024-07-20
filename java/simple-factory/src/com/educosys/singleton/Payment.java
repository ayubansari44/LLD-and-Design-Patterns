package com.educosys.singleton;

//Basic Without Multithreading
public class Payment {

    private static Payment instance;

    private Payment(){
        System.out.println("Payment obj initialized!");
    }

    public static Payment getInstance()
    {
        if(instance==null)
        {
            instance = new Payment();
        }
        return instance;
    }

    public void showMessage(){
        System.out.println("Singleton says hello!!!");
    }
}
