#include "TerranAirShip.h"

TerranAirShip::TerranAirShip(const AirShipType type, const int maxHealth, const int damage, const int shipId) :
    AirShip(type, maxHealth, damage, shipId), _passedTurns(1) {}

auto TerranAirShip::takeDamage(const int damage) -> void {
    _currHealth -= damage;
    if (_currHealth < 0)
        _currHealth = 0;
}

auto TerranAirShip::finishTurn() -> void { _passedTurns++; }
