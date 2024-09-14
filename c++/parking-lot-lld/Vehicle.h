#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

enum VehicleType
{
    TRUCK,
    BIKE,
    CAR
};

class Vehicle{
    protected:
        string licencePlate;
        VehicleType type;
    public:
        Vehicle(string licencePlate, VehicleType type);
        VehicleType getType();
        string getLicencePlate();
        
};

#endif