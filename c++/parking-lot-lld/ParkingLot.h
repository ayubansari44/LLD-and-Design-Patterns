#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include<bits/stdc++.h>
#include "Level.h"
#include "Vehicle.h"

using namespace std;

class ParkingLot
{
    private:
        static ParkingLot *instance;
        vector<Level*> levels;
    
    public:
        ParkingLot();
        static ParkingLot* getInstance();
        void addLevels(Level *level);
        bool parkVehicle(Vehicle *vehicle);
        bool unparkVehicle(Vehicle *vehicle);
        void displayParkingLot();

};

#endif