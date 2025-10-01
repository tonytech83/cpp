//
// Created by tonytech on 1.10.2025.
//

#ifndef CPP_XBOXCONSOLE_H
#define CPP_XBOXCONSOLE_H
#include "Console.h"

class XboxConsole : public Console {
public:
    XboxConsole(const int &price, const int &quality) : Console(price, quality) {}

    auto showPrint() const -> void {
        std::cout << "Xbox with ";
        print();
    }
};

#endif // CPP_XBOXCONSOLE_H
