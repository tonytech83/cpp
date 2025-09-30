#include <iostream>
using namespace std;

#include "Phoenix.h"

Phoenix::Phoenix(const AirShipType type, const int health, const int damage, const int maxShield,
                 const int shieldRegenerateRate, const int shipId) :
    ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId) {}


auto Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>> &enemyFleet) -> void {
    const auto target = enemyFleet.back().get();

    target->takeDamage(this->_damage);
    if (!target->isAlive()) {
        cout << "Phoenix with ID: " << this->getAirShipId()
             << " killed enemy airship with ID: " << target->getAirShipId() << endl;
        enemyFleet.pop_back();
    }

    // this->finishTurn();
}
