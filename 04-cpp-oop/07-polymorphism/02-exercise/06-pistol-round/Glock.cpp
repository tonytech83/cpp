//
// Created by tonytech on 16.09.2025.
//

#include "Glock.h"
#include "Shoot.h"
using namespace std;

Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo) :
    Pistol(damagePerRound, clipSize, remainingAmmo) {}


auto Glock::fire(PlayerVitalData &enemyPlayerData) -> bool {
    // calc damages
    const int armorDamage = _damagePerRound / 2;
    const int healthDamage = _damagePerRound - armorDamage;

    for (int i(0); i < ROUNDS_PER_FIRE && enemyPlayerData.health > 0; i++) {
        switch (shoot(_currClipBullets, armorDamage, healthDamage, enemyPlayerData)) {
            case RELOADING:
                reload();
                return false;

            case ALIVE:
                break;

            case DEAD: // DEAD or other :)
                return true;
        }
    }

    // for (int i(0); i < ROUNDS_PER_FIRE && enemyPlayerData.health > 0; i++) {
    //     if (_currClipBullets <= 0) {
    //         reload();
    //         return false; // enemy stay alive
    //     }
    //
    //     // fire once
    //     _currClipBullets--;
    //
    //     // calc damages
    //     const int armorDamage = _damagePerRound / 2;
    //     const int healthDamage = _damagePerRound - armorDamage;
    //
    //     enemyPlayerData.armor -= armorDamage;
    //     if (enemyPlayerData.armor < 0) {
    //         enemyPlayerData.health += enemyPlayerData.armor;
    //         enemyPlayerData.armor = 0;
    //     }
    //
    //     enemyPlayerData.health -= healthDamage;
    //     cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor"
    //          << endl;
    // }
    return false; // if we reach this return, this mean that enemy is alive
}
