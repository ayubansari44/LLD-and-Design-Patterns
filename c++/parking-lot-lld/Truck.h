#ifndef TRUCK_H
#define TRUCK_H

#include<iostream>
#include<bits/stdc++.h>
#include "Vehicle.h"

using namespace std;

class Truck : public Vehicle{
    public:
        Truck();
        Truck(string licencePlate);
    
};

#endif