#include "TrafficLight.h"

TrafficLight::TrafficLight(){}

TrafficLight::TrafficLight(string id, int red, int yellow, int green)
{
    this->id=id;
    this->redDuration=red;
    this->yellowDuration=yellow;
    this->greenDuration=green;
}

void TrafficLight::changeSignal(Signal newSignal)
{
    this->currSignal = newSignal;
    notifyObservers();
}

Signal TrafficLight::getCurrentSignal(){
    return currSignal;
}

int TrafficLight::getRedDuration(){
    vector<int> list;
    return redDuration;
}

int TrafficLight::getYellowDuration(){
    return yellowDuration;
}

int TrafficLight::getGreenDuration(){
    return greenDuration;
}

void TrafficLight::setRedDuration(int redDuration){
     this->redDuration = redDuration;
}

void TrafficLight::setYellowDuration(int yellowDuration){
     this->yellowDuration = yellowDuration;
}

void TrafficLight::setGreenDuration(int greenDuration){
     this->greenDuration = greenDuration;
}

void TrafficLight::notifyObservers()
{
    cout<<"Add code here to notify everyone!"<<endl;
}
