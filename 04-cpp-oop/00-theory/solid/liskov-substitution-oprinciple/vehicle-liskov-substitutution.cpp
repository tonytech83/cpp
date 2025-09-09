//
// Created by tonytech on 09.09.2025.
//
#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual auto drive() -> void { cout << "Driving vehicle..." << endl; }

    virtual ~Vehicle() = default;
};

class MotorizedVehicle : public Vehicle {
public:
    virtual auto startEngine() -> void { cout << "Starting engine..." << endl; };
    auto drive() -> void override { cout << "Driving motorized vehicle..." << endl; };
};

class Car : public MotorizedVehicle {
public:
    auto startEngine() -> void override { cout << "Starting cat engine..." << endl; }
    auto drive() -> void override { cout << "Driving car..." << endl; };
};

class NonMotorizedVehicle : public Vehicle {
public:
    // Non-motorized vehicle do not have engine
};

class Bicycle : public NonMotorizedVehicle {
    auto drive() -> void override { cout << "Driving bicycle..." << endl; };
};

auto useMotorizedVehicle(MotorizedVehicle &vehicle) -> void {
    vehicle.startEngine();
    vehicle.drive();
}

auto useVehicle(Vehicle &vehicle) -> void {
    // Cross cast, try to cast `vehicle` to MotorizedVehicle
    auto *motorized = dynamic_cast<MotorizedVehicle *>(&vehicle);
    if (motorized != nullptr)
        useMotorizedVehicle(*motorized);
    else
        vehicle.drive();
}

auto main() -> int {
    Car car;
    Bicycle bicycle;
    useVehicle(car);
    useVehicle(bicycle);

    return 0;
}
