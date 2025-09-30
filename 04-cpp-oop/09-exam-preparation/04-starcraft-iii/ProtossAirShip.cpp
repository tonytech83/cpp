#include "ProtossAirShip.h"

ProtossAirShip::ProtossAirShip(const AirShipType type, const int health, const int damage, const int maxShield,
                               const int shieldRegenerateRate, const int shipId) :
    AirShip(type, health, damage, shipId), _maxShield(maxShield), _currShield(maxShield),
    _shieldRegenerateRate(shieldRegenerateRate) {}


auto ProtossAirShip::takeDamage(const int damage) -> void {
    _currShield -= damage;

    if (_currShield < 0) {
        _currHealth += _currShield;
        _currShield = 0;
    }

    if (_currHealth < 0)
        _currHealth = 0;
}

auto ProtossAirShip::finishTurn() -> void {
    _currShield += _shieldRegenerateRate;
    if (_currShield > _maxShield)
        _currShield = _maxShield;
}
