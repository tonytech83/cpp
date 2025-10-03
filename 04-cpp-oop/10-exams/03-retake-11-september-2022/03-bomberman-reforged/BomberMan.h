//
// Created by tonytech on 3.10.2025.
//

#ifndef CPP_BOMBERMAN_H
#define CPP_BOMBERMAN_H

#include <vector>

#include "Defines.h"

class BomberMan {
    int _bombPower{0};

public:
    BomberMan();

    auto bombPowerUp() -> void;

    auto bombPowerDown() -> void;

    [[nodiscard]] auto getBombPower() const -> int;

    auto placeBomb(std::vector<std::vector<int>> &fieldData, const int &bombRow, const int &bombCol) -> int;
};

#endif // CPP_BOMBERMAN_H
