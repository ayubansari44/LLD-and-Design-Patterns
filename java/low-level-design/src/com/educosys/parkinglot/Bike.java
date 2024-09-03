package com.educosys.parkinglot;

public class Bike extends Vehicle{
    public Bike(){}

    public Bike(int regNo){
        this.regNo = regNo;
        this.type = VehicleType.BIKE;
    }
}
