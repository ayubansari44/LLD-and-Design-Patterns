package com.educosys.parkinglot;

import java.util.List;

public class ParkingLot {
    private static ParkingLot instance;
    private List<Level> levels;

    public static ParkingLot getInstance()
    {
        if(instance==null)
        {
            instance=new ParkingLot();
        }
        return instance;
    }

    public void addLevels(Level level)
    {
        this.levels.add(level);
    }

    public boolean parkVehicle(Vehicle vehicle)
    {
        for(Level level: levels)
        {
            if(level.parkVehicle(vehicle))
                    return true;
        }

        return false;
    }

    public boolean unparkVehicle(Vehicle vehicle)
    {
        for(Level level: levels)
        {
            if(level.unparkVehicle(vehicle))
                return true;
        }

        return false;
    }

    public void displayParking()
    {
        for(Level level: levels)
        {
            level.displayParking();
        }
    }

}
