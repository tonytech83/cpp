#include <iostream>
using namespace std;

#include "Carrier.h"


Carrier::Carrier(const AirShipType type, const int health, const int damage, const int maxShield,
                 const int shieldRegenerateRate, const int shipId) :
    ProtossAirShip(type, health, damage, maxShield, shieldRegenerateRate, shipId),
    _activeInterceptors(MAX_INTERCEPTORS) {}

auto Carrier::takeDamage(const int damage) -> void {
    ProtossAirShip::takeDamage(damage);
    if (this->_currHealth < this->_maxHealth)
        _activeInterceptors = DAMAGED_STATUS_INTERCEPTORS;
}

auto Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>> &enemyFleet) -> void {
    for (int interceptor(0); interceptor < _activeInterceptors; interceptor++) {
        const auto target = enemyFleet.back().get();
        const auto currDamage = _damage;
        target->takeDamage(currDamage);

        if (!target->isAlive()) {
            cout << "Carrier with ID: " << this->getAirShipId()
                 << " killed enemy airship with ID: " << target->getAirShipId() << endl;
            enemyFleet.pop_back();
        }

        if (enemyFleet.empty())
            break;
    }
}
