//
// Created by tonytech on 3.10.2025.
//

#include "AutomaticCar.h"

AutomaticCar::AutomaticCar(const int maxSpeed, const int fuel) : Car(maxSpeed, fuel) {}

auto AutomaticCar::increaseSpeed(const int speedIncrease, const int fuelConsumtion) -> void {
    this->_currSpeed += speedIncrease;

    this->fuel -= fuelConsumtion;
    if (this->fuel <= 0) {
        this->fuel = 0;
        this->_currSpeed = 0;
    } else {
        if (this->_currSpeed > this->maxSpeed)
            this->_currSpeed = this->maxSpeed;
    }
}

auto AutomaticCar::decreaseSpeed(int speedDecrease) -> void {
    this->_currSpeed -= speedDecrease * 2;
    if (this->_currSpeed < 0)
        this->_currSpeed = 0;
}
