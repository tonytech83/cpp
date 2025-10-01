//
// Created by tonytech on 1.10.2025.
//

#ifndef CPP_STRINGWRAPPER_H
#define CPP_STRINGWRAPPER_H

#include <iostream>
#include <string>

class StringWrapper {
    std::string line;
    char letter{};
    int repetitions{};

public:
    StringWrapper() {};
    StringWrapper(const std::string &line) : line(line) {}
    StringWrapper(const char &letter, const int &repetition) : letter(letter), repetitions(repetition) {}

    auto getContent() const -> std::string {
        if (!line.empty())
            // constructed with a string
            return line;

        // constructed with char + repetitions
        return std::string(repetitions, letter);
    }


    auto append(const std::string &content) -> StringWrapper &{
        this->line += content;
        return *this;
    }

    auto printContent() -> void { std::cout << this->getContent() << std::endl; }
};

#endif // CPP_STRINGWRAPPER_H
