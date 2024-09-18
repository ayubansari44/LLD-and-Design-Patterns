#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H
#include<bits/stdc++.h>
#include "Signal.h"
using namespace std;

class TrafficLight
{
    private:
        string id;
        Signal currSignal;
        int redDuration, yellowDuration, greenDuration;
    public:
        TrafficLight();
        TrafficLight(string id, int red, int yellow, int green);
        void changeSignal(Signal newSignal);
        Signal getCurrentSignal();
        int getRedDuration();
        int getYellowDuration();
        int getGreenDuration();
        void setRedDuration(int red);
        void setYellowDuration(int yellow);
        void setGreenDuration(int green);
        void notifyObservers();
};

#endif