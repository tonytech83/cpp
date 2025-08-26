//
// Created by tonytech on 22.08.2025.
//

#ifndef CPP_ECHO_H
#define CPP_ECHO_H

#include <iostream>
#include <string>

// Using `extern` only for declaration of variable which will be accessible from all files.
extern bool echoOn;

// We can use extern for function, but only for better readability
extern auto echo(const std::string &message) -> void;

#endif // CPP_ECHO_H
