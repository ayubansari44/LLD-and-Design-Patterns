package com.educosys.parkinglot;

public class Main {
    public static void main(String[] args)
    {
        System.out.println("### Welcome to Parking Lot System");
        ParkingLot instance = ParkingLot.getInstance();
        Vehicle bike = new Bike(123);
        Vehicle truck = new Truck(789);
        Vehicle car = new Car(456);

        Level level1 = new Level(1, 5, VehicleType.BIKE);
        Level level2 = new Level(2, 5, VehicleType.CAR);
        Level level3 = new Level(3, 5, VehicleType.TRUCK);

        instance.addLevels(level1);
        instance.addLevels(level2);
        instance.addLevels(level3);

        instance.parkVehicle(bike);
        instance.parkVehicle(truck);
        instance.parkVehicle(car);

        instance.displayParking();
    }
}
