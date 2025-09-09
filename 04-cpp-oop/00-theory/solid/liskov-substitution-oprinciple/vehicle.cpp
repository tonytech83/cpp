//
// Created by tonytech on 09.09.2025.
//
#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual auto startEngine() -> void { cout << "Starting engine..." << endl; }
    virtual auto drive() -> void { cout << "Driving vehicle..." << endl; }
};

class Car : public Vehicle {
public:
    auto startEngine() -> void override { cout << "Starting car engine..." << endl; }
    auto drive() -> void override { cout << "Driving car..." << endl; }
};

class Bicycle : public Vehicle {
public:
    auto drive() -> void override { cout << "Driving bicycle..." << endl; }
    auto startEngine() -> void override { throw runtime_error("Bicycle don't have engine!"); }
};

auto useVehicle(Vehicle &vehicle) -> void {
    vehicle.startEngine();
    vehicle.drive();
}

auto main() -> int {
    Car car;
    useVehicle(car);

    Bicycle bicycle;
    useVehicle(bicycle);

    return EXIT_SUCCESS;
}
