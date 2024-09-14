#include<bits/stdc++.h>
#include "Level.h"
using namespace std;
        
    Level::Level(){}

    Level::Level(int floorNo, int spotCount, VehicleType type)
    {
        this->floorNo = floorNo;
        for(int i=0;i<spotCount;i++){
            parkingSpots.push_back(new ParkingSpot(i, type));
        }
    }

    bool Level::parkVehicle(Vehicle *vehicle)
    {
        for(auto it: parkingSpots)
        {
            if(it->isParkingAvailable() && it->getVehicleType() == vehicle->getType()) {
                it->parkVehicle(vehicle);
                return true;
            }       
        }

        cout<<endl<<"Cannot park :( by Level"<<endl;
        return false;
    }

    bool Level::unparkVehicle(Vehicle *vehicle)
    {
        for(auto it: parkingSpots){
            if(vehicle == it->getParkedVehicle())
            {
                it->unparkVehicle();
                return true;
            }
        }
        return false;
    }

    void Level::displayLevels(){
        cout<<"Level:"<<floorNo<<endl;
        for(int i=0;i<parkingSpots.size();i++)
        {
            parkingSpots[i]->displayParking();
        }
    }