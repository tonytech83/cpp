//
// Created by tonytech on 1.10.2025.
//

#include "InputParser.h"

#include <iostream>
using namespace std;

auto readInput() -> Input {
    std::string _line;
    char _letter{};
    int _repetitions{};

    cin >> _line >> _letter >> _repetitions;

    auto input = Input();
    input.line = _line;
    input.letter = _letter;
    input.repetitions = _repetitions;

    return input;
}
