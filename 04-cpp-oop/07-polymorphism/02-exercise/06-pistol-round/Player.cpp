//
// Created by tonytech on 16.09.2025.
//

#include "Player.h"

#include "DesertEagle.h"
#include "Glock.h"

auto Player::buyPistol(const PistolType pistolType, const int damagePerRound, const int clipSize,
                       const int remainingAmmo) -> void {
    switch (pistolType) {
        case PistolType::GLOCK:
            _pistol = new Glock(damagePerRound, clipSize, remainingAmmo);
            break;
        case PistolType::DESERT_EAGLE:
            _pistol = new DesertEagle(damagePerRound, clipSize, remainingAmmo);
            break;
    }
}
