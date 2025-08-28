//
// Created by tonytech on 28.08.2025.
//

#ifndef CPP_WORD_H
#define CPP_WORD_H

#include <string>
#include <utility>

class Word {
    std::string word;
    mutable int count;

public:
    explicit Word(std::string word);

    auto operator<(const Word &prev) const -> bool;

    [[nodiscard]] auto getWord() const -> std::string;
    [[nodiscard]] auto getCount() const -> int;
};

#endif // CPP_WORD_H
