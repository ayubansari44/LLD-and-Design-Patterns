#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<bits/stdc++.h>
#include "Vehicle.h"

using namespace std;

class Car : public Vehicle{
    public:
        Car();
        Car(string licencePlate);
};

#endif