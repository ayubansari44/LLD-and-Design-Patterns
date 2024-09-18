#ifndef ROAD_H
#define ROAD_H
#include<bits/stdc++.h>
#include "TrafficLight.h"
using namespace std;

class Road
{
    private:
        string id;
        string name;
        TrafficLight *trafficLight;
    
    public:
        Road(string id, string name);
        void setTrafficLight(TrafficLight* newLight);
        TrafficLight* getTrafficLight();
        string getId();
};

#endif