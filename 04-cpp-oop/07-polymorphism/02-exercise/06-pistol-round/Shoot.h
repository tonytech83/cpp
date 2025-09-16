//
// Created by tonytech on 16.09.2025.
//

#ifndef CPP_SHOOT_H
#define CPP_SHOOT_H

#include "Structs.h"

enum SHOOTING_RESULT { RELOADING, DEAD, ALIVE };

SHOOTING_RESULT shoot(int &currClipBullets, const int &armorDamage, const int &healthDamage,
                      PlayerVitalData &enemyPlayerData);

#endif // CPP_SHOOT_H
