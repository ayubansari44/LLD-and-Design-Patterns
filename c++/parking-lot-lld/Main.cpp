#include<bits/stdc++.h>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Bike.h"
#include "ParkingSpot.h"
#include "Level.h"
#include "ParkingLot.h"


using namespace std;

int main()
{
    cout<<"### Welcome to Parking Lot system design"<<endl;
    
    Level *level1 = new Level(1, 5, VehicleType::BIKE);
    Level *level2 = new Level(2, 5,  VehicleType::TRUCK);
    Level *level3 = new Level(3, 5,  VehicleType::CAR);

    ParkingLot* instance = ParkingLot::getInstance();
    instance->addLevels(level1);
    instance->addLevels(level2);
    instance->addLevels(level3);

    Vehicle *car = new Car("1001");
    Vehicle *truck = new Truck("1002");
    Vehicle *bike = new Bike("1003");

    instance->parkVehicle(car);
    instance->parkVehicle(bike);
    instance->parkVehicle(truck);
    instance->displayParkingLot();

    cout<<endl<<"###############after unparking #################";
    instance->unparkVehicle(car);
    instance->displayParkingLot();

}