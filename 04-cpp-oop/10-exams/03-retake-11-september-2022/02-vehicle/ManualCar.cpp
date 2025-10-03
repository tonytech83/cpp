//
// Created by tonytech on 3.10.2025.
//
#include "ManualCar.h"

#include <cstddef>

ManualCar::ManualCar(const std::vector<int> &shiftSpeeds, const int maxSpeed, const int fuel) :
    Car(maxSpeed, fuel), _shiftSpeeds(shiftSpeeds) {}

auto ManualCar::increaseSpeed(const int speedIncrease, int fuelConsumtion) -> void {
    // set current speed
    this->_currSpeed += speedIncrease;

    // check shift for current speed
    std::size_t newShift = findShiftIdx();

    // calc fuel consumation based on new shift
    if (newShift > this->_currShiftIdx)
        fuelConsumtion *= 2;

    // update shift
    this->_currShiftIdx = newShift;

    this->fuel -= fuelConsumtion;
    if (this->fuel <= 0) {
        this->fuel = 0;
        this->_currSpeed = 0;
    } else {
        if (this->_currSpeed > this->maxSpeed)
            this->_currSpeed = this->maxSpeed;
    }
}
auto ManualCar::decreaseSpeed(const int speedDecrease) -> void {
    this->_currSpeed -= speedDecrease;
    if (this->_currSpeed < 0)
        this->_currSpeed = 0;
}

auto ManualCar::findShiftIdx() const -> std::size_t {
    for (std::size_t i(0); i < _shiftSpeeds.size(); ++i)
        if (_currSpeed < this->_shiftSpeeds[i])
            return i;

    return this->_currShiftIdx;
}
