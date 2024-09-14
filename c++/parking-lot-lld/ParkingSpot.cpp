#include "ParkingSpot.h"
using namespace std;

ParkingSpot::ParkingSpot(int spotNo, VehicleType type)
{
    this->parkedVehicle = NULL;
    this->spotNo = spotNo;
    this->vehicleType = type;
}

bool ParkingSpot::isParkingAvailable(){
    return this->parkedVehicle == NULL;
}

void ParkingSpot::parkVehicle(Vehicle *vehicle)
{
    if(isParkingAvailable() && vehicle->getType() == this->vehicleType)
    {
        this->parkedVehicle = vehicle;
    }
    else{
        cout<<endl<<"Parking Unsuccessful :( by ParkingSpot";
    }
}

void ParkingSpot::unparkVehicle(){
    this->parkedVehicle=NULL;
}

void ParkingSpot::displayParking()
{
    cout<<"Spot No:"<<this->spotNo<<", Availability:"<<(this->isParkingAvailable() ? "Available" : "Unavailable")<<endl;
}

Vehicle* ParkingSpot::getParkedVehicle(){
    return parkedVehicle;
}

VehicleType ParkingSpot::getVehicleType(){
    return vehicleType;
}