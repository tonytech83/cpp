//
// Created by tonytech on 3.10.2025.
//

#include <iostream>
#include <memory>

#include "AutomaticCar.h"
#include "ManualCar.h"
using namespace std;

#include "RaceTrack.h"


auto RaceTrack::isRaceRunning() const -> bool {
    // check for car with 0 fuel
    for (auto &car: this->_cars)
        if (car->fuel <= 0) {
            return false;
        }

    return true;
}

auto RaceTrack::printWinner() -> void {
    bool hasWinner = false;
    int winnerIdx = -1;

    // check for car with 0 fuel and if made other car winner
    for (int idx(0); idx < this->_cars.size(); idx++)
        if (this->_cars[idx]->fuel <= 0) {
            hasWinner = true;
            winnerIdx = (idx == 0 ? 1 : 0);
        }

    // both have fuel, decide by total distance
    if (!hasWinner)
        if (_cars[0]->_totalDistance != _cars[1]->_totalDistance) {
            hasWinner = true;
            winnerIdx = (_cars[0]->_totalDistance > _cars[1]->_totalDistance ? 0 : 1);
        }

    if (hasWinner)
        cout << "Car with index: " << winnerIdx << " won!" << endl;
    else
        cout << "No winner" << endl;
}

auto RaceTrack::createManualCar(const std::vector<int> &shifts, int maxSpeed, int startFuel) -> void {
    auto newCar = std::make_unique<ManualCar>(shifts, maxSpeed, startFuel);
    this->_cars.push_back(std::move(newCar));
}

auto RaceTrack::createAutomaticCar(int maxSpeed, int startFuel) -> void {
    auto newCar = std::make_unique<AutomaticCar>(maxSpeed, startFuel);
    this->_cars.push_back(std::move(newCar));
}

auto RaceTrack::increaseSpeed(int speedIncrease, int fuelConsumtion) -> void {
    for (auto &car: this->_cars)
        car->increaseSpeed(speedIncrease, fuelConsumtion);
}

auto RaceTrack::decreaseSpeed(int speedDecrease) -> void {
    for (auto &car: this->_cars)
        car->decreaseSpeed(speedDecrease);
}

auto RaceTrack::advance() -> void {
    for (auto &car: this->_cars)
        car->_totalDistance += car->_currSpeed;
}

auto RaceTrack::printInfo() const -> void {
    for (int idx(0); idx < this->_cars.size(); idx++)
        cout << "Car with index: " << idx << " has totalDistance: " << _cars[idx]->_totalDistance
             << ", is running with " << _cars[idx]->_currSpeed << " speed, has " << _cars[idx]->fuel << " fuel left"
             << endl;
}
