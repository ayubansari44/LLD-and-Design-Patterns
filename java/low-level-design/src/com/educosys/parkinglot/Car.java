package com.educosys.parkinglot;

public class Car extends Vehicle {
    public Car(){}

    public Car(int regNo){
        this.regNo = regNo;
        this.type = VehicleType.CAR;
    }
}
