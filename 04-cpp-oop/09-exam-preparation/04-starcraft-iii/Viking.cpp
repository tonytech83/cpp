#include <iostream>
using namespace std;

#include "Viking.h"

Viking::Viking(const AirShipType type, const int health, const int baseDamage, const int shipId) :
    TerranAirShip(type, health, baseDamage, shipId) {}


auto Viking::dealDamage(std::vector<std::unique_ptr<AirShip>> &enemyFleet) -> void {
    const auto target = enemyFleet.back().get();
    int currDamage = this->_damage;

    if (target->getAirShipType() == AirShipType::PHOENIX)
        currDamage *= 2;

    target->takeDamage(currDamage);

    if (!target->isAlive()) {
        cout << "Viking with ID: " << this->getAirShipId()
             << " killed enemy airship with ID: " << target->getAirShipId() << endl;
        enemyFleet.pop_back();
    }
};
