#ifndef TRAFFICCONTROLLER_H
#define TRAFFICCONTROLLER_H
#include <bits/stdc++.h>
#include "Road.h"
#include "TrafficLight.h"
using namespace std;

class TrafficController
{
    private:
        static TrafficController* instance;
        map<string, Road*> roads;
    
    public:
        TrafficController();
        static TrafficController* getInstance();
        void addRoad(Road* road);
        void removeRoad(Road *road);
        void startTrafficController();
        void handleEmergency(string roadId);
};

#endif