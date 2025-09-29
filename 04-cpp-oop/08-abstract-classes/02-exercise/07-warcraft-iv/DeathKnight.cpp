//
// Created by tonytech on 29.9.2025.
//

#include <iostream>
using namespace std;

#include "DeathKnight.h"

DeathKnight::DeathKnight(const std::string &name, const int maxMana, const int baseManaRegenRate) :
    Hero(name, maxMana, baseManaRegenRate) {}

auto DeathKnight::castSpell(const SpellType spell) -> void {
    auto currSpell = this->_spells[spell];

    if (currSpell.manaCost <= this->_currMana) {
        cout << this->_name << " casted " << currSpell.name << " for " << currSpell.manaCost << " mana" << endl;
        this->_currMana -= currSpell.manaCost;

        if (spell == SpellType::ULTIMATE)
            cout << this->_name << " casted " << this->_spells[BASIC].name << " for 0 mana" << endl;

    } else {
        cout << this->_name << " - not enough mana to cast " << currSpell.name << endl;
    }
}

auto DeathKnight::regenerateMana() -> void {
    this->_currMana += this->_manaRegenRate;
    if (this->_currMana > this->_maxMana)
        this->_currMana = this->_maxMana;
}
