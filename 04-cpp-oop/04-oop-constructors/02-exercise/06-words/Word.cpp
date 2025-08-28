//
// Created by tonytech on 28.08.2025.
//

#include "Word.h"

Word::Word(std::string word) : word(std::move(word)), count(1) {}

auto Word::operator<(const Word &prev) const -> bool {
    if (word == prev.word)
        prev.count++;

    return word < prev.word;
}

[[nodiscard]] auto Word::getWord() const -> std::string { return this->word; }
[[nodiscard]] auto Word::getCount() const -> int { return this->count; }
