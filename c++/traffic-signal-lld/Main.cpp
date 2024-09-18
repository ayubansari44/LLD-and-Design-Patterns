#include<bits/stdc++.h>
#include "TrafficController.h"
using namespace std;

int main()
{
    cout<<"######### Welcome to Traffic Signal Control System ##############";
    TrafficController *instance = TrafficController::getInstance();

    Road *road1 = new Road("r1", "Main Street");
    Road *road2 = new Road("r2", "Not Street");
    Road *road3 = new Road("r3", "Main Street");
    Road *road4 = new Road("r4", "Main Street");

    TrafficLight *light1 = new TrafficLight("l1", 6000, 3000, 9000);
    TrafficLight *light2 = new TrafficLight("l2", 6000, 3000, 9000);
    TrafficLight *light3 = new TrafficLight("l3", 6000, 3000, 9000);
    TrafficLight *light4 = new TrafficLight("l4", 6000, 3000, 9000);

    road1->setTrafficLight(light1);
    road2->setTrafficLight(light2);
    road3->setTrafficLight(light3);
    road4->setTrafficLight(light4);

    instance->addRoad(road1);
    instance->addRoad(road2);
    instance->addRoad(road3);
    instance->addRoad(road4);

    instance->startTrafficController();
    instance->handleEmergency("r2");
}