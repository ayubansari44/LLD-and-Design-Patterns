package com.educosys.observerSwiggy;

import java.util.ArrayList;
import java.util.List;

public class Order {
    private List<IObserver> observerList;

    public Order(){
        observerList = new ArrayList<>();
    }

    public void subscribe(IObserver obs)
    {
        observerList.add(obs);
    }

    public void unsubscribe(IObserver obs)
    {
        observerList.remove(obs);
    }

    public void notifyAll(String msg)
    {
        for(IObserver it: observerList)
        {
            it.notify(msg);
        }
    }
}
