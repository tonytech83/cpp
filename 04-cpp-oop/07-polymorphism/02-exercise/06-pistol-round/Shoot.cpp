//
// Created by tonytech on 16.09.2025.
//

#include "Shoot.h"
#include <iostream>

using namespace std;

SHOOTING_RESULT shoot(int &currClipBullets, const int &armorDamage, const int &healthDamage,
                      PlayerVitalData &enemyPlayerData) {
    if (currClipBullets <= 0)
        return SHOOTING_RESULT::RELOADING; // enemy stay alive

    // fire once
    currClipBullets--;

    enemyPlayerData.armor -= armorDamage;
    if (enemyPlayerData.armor < 0) {
        enemyPlayerData.health += enemyPlayerData.armor;
        enemyPlayerData.armor = 0;
    }

    enemyPlayerData.health -= healthDamage;
    cout << "Enemy left with: " << enemyPlayerData.health << " health and " << enemyPlayerData.armor << " armor"
         << endl;

    return enemyPlayerData.health <= 0 ? DEAD : ALIVE;
}
