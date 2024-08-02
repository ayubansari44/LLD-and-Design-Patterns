package com.educosys.observer;

import java.util.ArrayList;
import java.util.List;

public class Group {
    private List<ISubscriber> userList;

    Group(){
        userList = new ArrayList<>();
    }

    public void subscribe(ISubscriber user)
    {
        userList.add(user);
    }

    public void unsubscribe(ISubscriber user)
    {
        userList.remove(user);
    }

    public void notify(String msg)
    {
        for(ISubscriber it: userList)
        {
            it.notify(msg);
        }
    }

}
