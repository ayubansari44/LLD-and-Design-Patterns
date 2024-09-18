#include "TrafficController.h"

TrafficController* TrafficController::instance=NULL;

TrafficController::TrafficController(){}

TrafficController* TrafficController::getInstance()
{
    if(instance==NULL)
        instance=new TrafficController();
    
    return instance;
}

void TrafficController::addRoad(Road* road){
    roads[road->getId()] = road;
}

void TrafficController::removeRoad(Road *road){
    roads.erase(road->getId());
}

void TrafficController::startTrafficController()
{
    for(auto road: roads)
    {
        TrafficLight *light = road.second->getTrafficLight();
        
        //################do the thread stuff for Later#############
        return;
    }
}

void TrafficController::handleEmergency(string roadId)
{
    Road *road = roads[roadId];
    if(road != NULL)
    {
        TrafficLight* light = road->getTrafficLight();
        light->changeSignal(Signal::GREEN);

    }
}