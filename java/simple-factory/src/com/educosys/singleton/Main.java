package com.educosys.singleton;

public class Main {
    public static void main(String args[])
    {
//        Payment obj1 = Payment.getInstance();
//        obj1.showMessage();
//
//        Payment obj2 = Payment.getInstance();
//        obj2.showMessage();

        PaymentMultithread o1 = PaymentMultithread.getInstance();
        o1.showMessage();

        PaymentMultithread o2 = PaymentMultithread.getInstance();
        o2.showMessage();

    }
}
