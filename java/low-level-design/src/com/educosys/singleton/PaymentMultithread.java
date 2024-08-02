package com.educosys.singleton;

import java.util.concurrent.locks.ReentrantLock;

public class PaymentMultithread {
    private static PaymentMultithread instance;
    private static ReentrantLock lock = new ReentrantLock();

    private PaymentMultithread(){
        System.out.println("PaymentMultithread obj initialized!");
    }

    public static PaymentMultithread getInstance()
    {
        if(instance==null)
        {
            lock.lock();
            try{
                if(instance==null) {
                    instance = new PaymentMultithread();
                }
            }finally{
                lock.unlock();
            }
        }
        return instance;
    }

    public void showMessage(){
        System.out.println("SingletonMultithread says hello!!!");
    }
}
