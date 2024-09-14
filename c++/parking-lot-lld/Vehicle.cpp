#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(string licencePlate, VehicleType type)
{
    this->licencePlate = licencePlate;
    this->type = type;
}

VehicleType Vehicle::getType(){
    return type;
}

string Vehicle::getLicencePlate(){
    return licencePlate;
}
