//
// Created by tonytech on 29.9.2025.
//
#include <iostream>
using namespace std;

#include "DrawRanger.h"

DrawRanger::DrawRanger(const std::string &name, const int maxMana, const int baseManaRegenRate) :
    Hero(name, maxMana, baseManaRegenRate) {}

auto DrawRanger::castSpell(const SpellType spell) -> void {
    auto currSpell = this->_spells[spell];

    if (currSpell.manaCost <= this->_currMana) {
        cout << this->_name << " casted " << currSpell.name << " for " << currSpell.manaCost << " mana" << endl;
        this->_currMana -= currSpell.manaCost;

        if (spell == SpellType::BASIC)
            cout << this->_name << " casted " << this->_spells[BASIC].name << " for 0 mana" << endl;

    } else {
        cout << this->_name << " - not enough mana to cast " << currSpell.name << endl;
    }
}

auto DrawRanger::regenerateMana() -> void {
    this->_currMana += this->_manaRegenRate;
    if (this->_currMana > this->_maxMana)
        this->_currMana = this->_maxMana;
}
