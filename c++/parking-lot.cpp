#include<bits/stdc++.h>
using namespace std;

enum VehicleType{
    CAR,
    BIKE,
    TRUCK
};

class Vehicle{
    protected:
        string licencePlate;
        VehicleType type;
    public:
        Vehicle(string licencePlate, VehicleType type)
        {
            this->licencePlate = licencePlate;
            this->type = type;
        }

        VehicleType getType()
        {
            return type;
        }
};

class Car : public Vehicle{
    public:
        Car(string licencePlate): Vehicle(licencePlate, VehicleType::CAR)
        {
            
        }
};

class Bike : public Vehicle{
    public:
        Bike(string licencePlate): Vehicle(licencePlate, VehicleType::BIKE)
        {
            
        }
};

class Truck : public Vehicle{
    public:
        Truck(string licencePlate): Vehicle(licencePlate, VehicleType::TRUCK)
        {
            
        }
};

class ParkingSpot
{
    private:
        int spotNo;
        Vehicle *parkedVehicle;
        VehicleType vehicleType;
    
    public:
        ParkingSpot(){

        }

        ParkingSpot(int no, VehicleType type)
        {
            this->spotNo=no;
            vehicleType = type; //default type is CAR
        }

        bool isAvailable(){
            return parkedVehicle==NULL;
        }

        int getSpotNo(){
            return spotNo;
        }

        VehicleType getVehicleType(){
            return vehicleType;
        }

        Vehicle* getParkedVehicle(){
            return parkedVehicle;
        }

        void parkVehicle(Vehicle *v)
        {
            if(isAvailable() && v->getType() == vehicleType){
                parkedVehicle = v;
            }
            else{
                cout<<"Invalid Vehicle type or Parking Spot occupied :(";
            }
        }

        void unparkVehicle()
        {
            parkedVehicle = NULL;
        }
};

class Level{
    private:
        int floor;
        vector<ParkingSpot*> parkingSpots;
    public:
        Level(int floor, int numSpots, VehicleType type)
        {
            this->floor=floor;
            parkingSpots.resize(numSpots);
            for(int i=0;i<numSpots;i++){
                parkingSpots[i] = new ParkingSpot(i, type);
            }
        }

        bool parkVehicle(Vehicle* v)
        {
            for(auto it: parkingSpots)
            {
                if(it->isAvailable() && v->getType() == it->getVehicleType())
                {
                    it->parkVehicle(v);
                    return true;
                }
            }
            return false;
        }

        bool unparkVehicle(Vehicle *v)
        {
            for(auto it: parkingSpots)
            {
                if(!it->isAvailable() && v == it->getParkedVehicle())
                {
                    it->unparkVehicle();
                    return true;
                }
            }
            return false;
        }

        void displayAvailability()
        {
            cout<<"Level:"<<floor<<endl;
            for(auto it: parkingSpots){
                cout<<"Spot No:"<<it->getSpotNo()<<", Availablity:"<<(it->isAvailable() ? "Available" : "Occupied")<<endl;
            }
        }

};

class ParkingLot{
    private:
        vector<Level*> levels;
        static ParkingLot *instance;
    
    public:
    
        static ParkingLot* getInstance()
        {
            if(instance==NULL)
                instance=new ParkingLot();
            
            return instance;
        }

        void addLevels(Level* level){
            levels.push_back(level);
        }

        bool parkVehicle(Vehicle* v)
        {
            for(auto it: levels)
            {
                if(it->parkVehicle(v) == true)
                    return true;
            }

            return false;
        }

        bool unparkVehicle(Vehicle *v)
        {
            for(auto it: levels)
            {
                if(it->unparkVehicle(v) == true)
                    return true;
            }

            return false;
        }

        void displayAvailability()
        {
            for(auto it: levels)
            {
                it->displayAvailability();
            }
        }

};

ParkingLot* ParkingLot :: instance = NULL;

int main()
{
    ParkingLot *parkingLot = ParkingLot::getInstance();
    parkingLot->addLevels(new Level(1, 6, VehicleType::CAR));
    parkingLot->addLevels(new Level(2, 5, VehicleType::BIKE));
    parkingLot->addLevels(new Level(3, 3, VehicleType::TRUCK));

    Vehicle *car = new Car("KA-25");
    Vehicle *bike = new Bike("KA-09");
    Vehicle *truck = new Truck("KA-01");

    parkingLot->parkVehicle(car);
    parkingLot->parkVehicle(bike);
    parkingLot->parkVehicle(truck);
    parkingLot->displayAvailability();

    parkingLot->unparkVehicle(car);
    parkingLot->displayAvailability();
}