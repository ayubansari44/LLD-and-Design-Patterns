#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include<bits/stdc++.h>
#include "Vehicle.h"

using namespace std;

class ParkingSpot
{
    private:
        int spotNo;
        Vehicle *parkedVehicle;
        VehicleType vehicleType;
    
    public:
        ParkingSpot(int spotNo, VehicleType type);

        bool isParkingAvailable();

        int getSpotNo();

        VehicleType getVehicleType();

        void parkVehicle(Vehicle *vehicle);

        void unparkVehicle();

        void displayParking();

        int getVehicleId();

        Vehicle* getParkedVehicle();
};

#endif