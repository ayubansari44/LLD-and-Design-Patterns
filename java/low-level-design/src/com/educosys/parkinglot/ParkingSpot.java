package com.educosys.parkinglot;

public class ParkingSpot {
    private int spotNo;
    private Vehicle vehicle;
    private VehicleType type;

    public ParkingSpot() {}

    public ParkingSpot(int spotNo, VehicleType type ) {
        this.spotNo = spotNo;
        this.type = type;
    }

    public boolean isAvailable(){
        return vehicle == null;
    }

    public void parkVehicle(Vehicle vehicle)
    {
        if(isAvailable() && type == vehicle.getType())
            this.vehicle = vehicle;

        else
            System.out.println("### Parking spot is not empty");
    }

    public void unparkVehicle()
    {
        this.vehicle = null;
    }

    public int getSpotNo() {
        return spotNo;
    }

    public void setSpotNo(int spotNo) {
        this.spotNo = spotNo;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public void setVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
    }

    public VehicleType getType() {
        return type;
    }

    public void setType(VehicleType type) {
        this.type = type;
    }
}
