package com.educosys.parkinglot;

public class Vehicle {
    int regNo;
    VehicleType type;

    Vehicle() {}

    Vehicle(int regNo, VehicleType type) {
        this.regNo = regNo;
        this.type = type;
    }

    public int getRegNo() {
        return regNo;
    }

    public void setRegNo(int regNo) {
        this.regNo = regNo;
    }

    public VehicleType getType() {
        return type;
    }

    public void setType(VehicleType type) {
        this.type = type;
    }
}
