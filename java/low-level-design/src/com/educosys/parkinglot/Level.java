package com.educosys.parkinglot;

import java.util.ArrayList;
import java.util.List;

public class Level {
    private int floorNo;
    private List<ParkingSpot> parkingSpots;

    public Level(){}
    
    public Level(int floorNo, int totalSpots, VehicleType type) {
        this.floorNo = floorNo;
        parkingSpots = new ArrayList<>(totalSpots);
        for(int i=0;i<totalSpots;i++)
        {
            parkingSpots.add(new ParkingSpot(i, type));
        }
    }

    public boolean parkVehicle(Vehicle vehicle)
    {
        for(ParkingSpot parkingSpot: parkingSpots)
        {
            if(parkingSpot.isAvailable() && parkingSpot.getType() == vehicle.getType())
            {
                parkingSpot.parkVehicle(vehicle);
                return true;
            }
        }

        return false;
    }

    public boolean unparkVehicle(Vehicle vehicle)
    {
        for(ParkingSpot parkingSpot: parkingSpots)
        {
            if((parkingSpot.getVehicle() == vehicle) && (!parkingSpot.isAvailable()))
            {
                parkingSpot.unparkVehicle();
                return true;
            }
        }
        return false;
    }

    public void displayParking()
    {
        for(ParkingSpot parkingSpot: parkingSpots)
        {
            System.out.println("Spot No:" + parkingSpot.getSpotNo() + "Availability:" + parkingSpot.isAvailable());
        }
    }
}
