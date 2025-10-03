//
// Created by tonytech on 3.10.2025.
//

#ifndef CPP_CAR_H
#define CPP_CAR_H

#include <cstddef>

class Car {

public:
    Car(int maxSpeed, int fuel) : maxSpeed(maxSpeed), fuel(fuel) {}

    virtual auto increaseSpeed(int speedIncrease, int fuelConsumtion) -> void = 0;
    virtual auto decreaseSpeed(int speedDecrease) -> void = 0;

    virtual ~Car() = default;

    int maxSpeed;
    int fuel;
    int _currSpeed{0};
    int _totalDistance{0};
};

#endif // CPP_CAR_H
