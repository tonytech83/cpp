#include <iostream>
using namespace std;

#include "BattleCruser.h"

BattleCruser::BattleCruser(const AirShipType type, const int health, const int damage, const int shipId) :
    TerranAirShip(type, health, damage, shipId) {}


auto BattleCruser::dealDamage(std::vector<std::unique_ptr<AirShip>> &enemyFleet) -> void {
    const auto target = enemyFleet.back().get();
    int currDamage = this->_damage;

    if (this->_passedTurns % (YAMATO_CANNON_LOADING_TIME + 1) == 0)
        currDamage *= 5;

    target->takeDamage(currDamage);

    if (!target->isAlive()) {
        cout << "BattleCruser with ID: " << this->getAirShipId()
             << " killed enemy airship with ID: " << target->getAirShipId() << endl;
        enemyFleet.pop_back();
    }
}
