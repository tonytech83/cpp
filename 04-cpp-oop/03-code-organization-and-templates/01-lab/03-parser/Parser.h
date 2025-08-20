//
// Created by tonytech on 19.08.2025.
//

#ifndef CPP_PARSER_H
#define CPP_PARSER_H

#include <sstream>
#include <string>

template<typename T>
class Parser {
    std::istream &input;
    std::string stopLine;

public:
    Parser(std::istream &input, std::string stopLine) : input(input), stopLine(std::move(stopLine)) {}

    auto readNext(T &element) -> bool {
        std::string currentLine;
        std::getline(input, currentLine);
        if (currentLine == stopLine)
            return false;

        std::istringstream iss(currentLine);
        iss >> element;
        return true;
    }
};

#endif // CPP_PARSER_H
