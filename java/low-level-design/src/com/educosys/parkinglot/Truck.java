package com.educosys.parkinglot;

public class Truck extends Vehicle{

    public Truck(){}

    public Truck(int regNo){
        this.regNo = regNo;
        this.type = VehicleType.TRUCK;
    }
}
