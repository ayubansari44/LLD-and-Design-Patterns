package com.educosys.singleton;

public class Main {
    public static void main(String args[])
    {
        Payment obj1 = Payment.getInstance();
        obj1.showMessage();

        Payment obj2 = Payment.getInstance();
        obj2.showMessage();

    }
}
