//
// Created by tonytech on 1.10.2025.
//

#ifndef CPP_BARBARIAN_H
#define CPP_BARBARIAN_H

#include <iostream>

#include "Hero.h"

class Barbarian final : public Hero {
    int _defends = 0;

public:
    Barbarian() : Hero() {};

    Barbarian(const VitalData &vitalData) {
        _vitalData = vitalData;
        _name = BARBARIAN_NAME;
    }

    auto readSpellFromInput(SpellType spellType) -> void override {
        SpellData spell;

        if (spellType == SpellType::Weak) {
            std::cin >> spell.name >> spell.damage;
            spell.manaCost = 0;
        } else if (spellType == SpellType::Strong) {
            std::cin >> spell.name >> spell.damage >> spell.manaCost;
        }

        _spells[static_cast<int>(spellType)] = spell;
    }

    // returns the produced damage
    auto castSpell() -> int override {
        int idx = (_vitalData.currMana >= _spells[1].manaCost) ? 1 : 0;

        _vitalData.currMana -= _spells[idx].manaCost;

        std::cout << _name << " casting " << _spells[idx].name << " for " << _spells[idx].manaCost << " mana"
                  << std::endl;

        return _spells[idx].damage;
    }

    auto takeDamage(int damage) -> void override {
        _defends++;
        const int curDamage = (_defends % 3 == 0 ? damage / 2 : damage);
        _vitalData.health -= curDamage;
        std::cout << "Barbarian took " << curDamage << " damage and is left with " << _vitalData.health << " health "
                  << std::endl;
    }

    auto regenerate() -> void override {
        const int before = _vitalData.currMana;

        _vitalData.currMana += _vitalData.manaRegenRate;
        if (_vitalData.currMana > _vitalData.maxMana)
            _vitalData.currMana = _vitalData.maxMana;

        const int gained = _vitalData.currMana - before;

        std::cout << "Barbarian regained " << gained << " mana for up to " << _vitalData.currMana << std::endl;
    }

    auto isDead() const -> bool override { return _vitalData.health <= 0; }
};

#endif // CPP_BARBARIAN_H
