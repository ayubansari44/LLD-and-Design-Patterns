#include<bits/stdc++.h>
#include "Level.h"
#include "Vehicle.h"
#include "ParkingLot.h"

using namespace std;

ParkingLot* ParkingLot::instance = NULL;

ParkingLot::ParkingLot(){}

ParkingLot* ParkingLot::getInstance()
{
    if(instance==NULL){
        instance = new ParkingLot();
    }
    return instance;
}

void ParkingLot::addLevels(Level *level){
    this->levels.push_back(level);
}

bool ParkingLot::parkVehicle(Vehicle *vehicle)
{
    for(auto floor: levels)
    {
        if(floor->parkVehicle(vehicle) == true)
            return true;
    }

    return false;
}

bool ParkingLot::unparkVehicle(Vehicle *vehicle)
{
    for(auto floor: levels)
    {
        if(floor->unparkVehicle(vehicle) == true)
            return true;
    }
    return false;
}

void ParkingLot::displayParkingLot()
{
    for(auto it: levels)
    {
        it->displayLevels();
    }
}
