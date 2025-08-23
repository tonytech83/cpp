//
// Created by tonytech on 23.8.2025.
//
#include "Echo.h"

bool echoOn = true;

auto echo(const std::string &message) -> void {
    if (echoOn)
        std::cout << message << std::endl;
};
