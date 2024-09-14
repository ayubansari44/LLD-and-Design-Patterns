#ifndef LEVEL_H
#define LEVEL_H

#include<bits/stdc++.h>
#include "ParkingSpot.h"
using namespace std;

class Level
{
    private:
        vector<ParkingSpot*> parkingSpots;
        int floorNo;
    public:
        Level();

        Level(int floorNo, int spotCount, VehicleType type);

        bool parkVehicle(Vehicle *vehicle);

        bool unparkVehicle(Vehicle *vehicle);

        void displayLevels();
};

#endif