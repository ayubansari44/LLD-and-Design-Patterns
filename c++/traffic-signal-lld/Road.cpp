#include "Road.h"

Road::Road(string id, string name){
    this->id = id;
    this->name=name;
}

void Road::setTrafficLight(TrafficLight *trafficLight)
{
    this->trafficLight = trafficLight;
}

TrafficLight* Road::getTrafficLight(){
    return trafficLight;
}

string Road::getId(){
    return id;
}


