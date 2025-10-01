//
// Created by tonytech on 1.10.2025.
//

#ifndef CPP_PSCONSOLE_H
#define CPP_PSCONSOLE_H

#include "Console.h"

class PSConsole : public Console {
    int _generation;

public:
    PSConsole(const int &price, const int &quality, const int &generation) :
        Console(price, quality), _generation(generation) {}

    auto getGeneration() const -> int { return _generation; }

    auto showPrint() const -> void {
        std::cout << "PS with generation " << getGeneration() << ", ";
        print();
    }
};

#endif // CPP_PSCONSOLE_H
