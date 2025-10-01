//
// Created by tonytech on 1.10.2025.
//

#include <iostream>
#include <memory>
#include <vector>

#include "Hero.h"

#ifndef CPP_BATTLEFIELD_H
#define CPP_BATTLEFIELD_H

class BattleField {
    std::vector<std::unique_ptr<Hero>> _heroes;
public:
    BattleField() = default;

    auto createHeroes() -> void;

    auto createSpells() -> void;

    auto startBattle() -> void;

    auto printWinner(const std::unique_ptr<Hero> &hero) -> void;
};

#endif // CPP_BATTLEFIELD_H
