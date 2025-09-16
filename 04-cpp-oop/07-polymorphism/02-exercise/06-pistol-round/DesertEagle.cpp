//
// Created by tonytech on 16.09.2025.
//

#include "DesertEagle.h"
#include "Shoot.h"
using namespace std;

// constexpr int DESERT_EAGLE_ARMOR_DAMAGE = 4;

DesertEagle::DesertEagle(const int damagePerRound, const int clipSize, const int remainingAmmo) :
    Pistol(damagePerRound, clipSize, remainingAmmo) {}

auto DesertEagle::fire(PlayerVitalData &enemyPlayerData) -> bool {
    // calc damages
    const int armorDamage = _damagePerRound / 4;
    const int healthDamage = _damagePerRound - armorDamage;

    switch (shoot(_currClipBullets, armorDamage, healthDamage, enemyPlayerData)) {
        case RELOADING:
            reload();
            return false;
        case ALIVE:
            return false;
        default: // DEAD or other :)
            return true;
    }

    // if (_currClipBullets <= 0) {
    //     reload();
    //     return false; // enemy stay alive
    // }
    //
    // // fire once
    // _currClipBullets--;
    //
    // // calc damages
    // const int armorDamage = _damagePerRound / 4;
    // const int healthDamage = _damagePerRound - armorDamage;
    //
    // enemyPlayerData.armor -= armorDamage;
    // if (enemyPlayerData.armor < 0) {
    //     enemyPlayerData.health += enemyPlayerData.armor;
    //     enemyPlayerData.armor = 0;
    // }
    //
    // enemyPlayerData.health -= healthDamage;
    // cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor"
    //      << endl;
    //
    // return enemyPlayerData.health <= 0;
}
