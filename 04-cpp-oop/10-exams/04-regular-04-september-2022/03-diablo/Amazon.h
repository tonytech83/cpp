//
// Created by tonytech on 1.10.2025.
//

#ifndef CPP_AMAZON_H
#define CPP_AMAZON_H

class Amazon final : public Hero {
    int _attack = 1;

public:
    Amazon() = default;
    Amazon(const VitalData &vitalData) {
        _vitalData = vitalData;
        _name = AMAZON_NAME;
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
        int currDamage = _attack % 2 == 0 ? _spells[idx].damage * 1.25 : _spells[idx].damage;
        _attack++;
        return currDamage;
    }

    auto takeDamage(int damage) -> void override {
        _vitalData.health -= damage;
        std::cout << "Amazon took " << damage << " damage and is left with " << _vitalData.health << " health "
                  << std::endl;
    }

    auto regenerate() -> void override {
        const int before = _vitalData.currMana;

        _vitalData.currMana += _vitalData.manaRegenRate;
        if (_vitalData.currMana > _vitalData.maxMana)
            _vitalData.currMana = _vitalData.maxMana;

        const int gained = _vitalData.currMana - before;

        std::cout << "Amazon regained " << gained << " mana for up to " << _vitalData.currMana << std::endl;
    }

    auto isDead() const -> bool override { return _vitalData.health <= 0; }
};

#endif // CPP_AMAZON_H
