//
// Created by tonytech on 29.9.2025.
//
#include <iostream>
using namespace std;

#include "Archmage.h"

Archmage::Archmage(const std::string &name, const int maxMana, const int baseManaRegenRate,
                   const int manaRegenModifier) :
    Hero(name, maxMana, baseManaRegenRate), _manaRegenModifier(manaRegenModifier) {}

auto Archmage::castSpell(const SpellType spell) -> void {
    auto currSpell = this->_spells[spell];

    if (currSpell.manaCost <= this->_currMana) {
        cout << this->_name << " casted " << currSpell.name << " for " << currSpell.manaCost << " mana" << endl;
        this->_currMana -= currSpell.manaCost;

        if (spell == SpellType::ULTIMATE)
            this->regenerateMana();

    } else {
        cout << this->_name << " - not enough mana to cast " << currSpell.name << endl;
    }
}

auto Archmage::regenerateMana() -> void {
    this->_currMana += (this->_manaRegenRate * this->_manaRegenModifier);
    if (this->_currMana > this->_maxMana)
        this->_currMana = this->_maxMana;
}
