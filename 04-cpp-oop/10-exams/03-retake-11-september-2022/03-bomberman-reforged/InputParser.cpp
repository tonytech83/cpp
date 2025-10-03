//
// Created by tonytech on 3.10.2025.
//
#include "InputParser.h"

#include <iostream>
#include <sstream>
using namespace std;

auto InputParser::readField() const -> FieldData {
    int rows, cols;
    cin >> rows >> cols;
    cin.ignore();

    FieldData field;

    for (int i(0); i < rows; i++) {
        string line;
        getline(cin, line);
        field.push_back(line);
    }

    // FieldData = { "0123", "4567", "8901" }
    return field;
}

auto InputParser::readCommands() const -> std::vector<Command> {
    int commandsCount;
    cin >> commandsCount;
    cin.ignore();

    vector<Command> commands;
    commands.reserve(commandsCount);

    for (int i = 0; i < commandsCount; i++) {
        string line;
        getline(cin, line);

        auto c = Command();

        if (line == "power up") {
            c.type = CommandType::POWER_UP;
        } else if (line == "power down") {
            c.type = CommandType::POWER_DOWN;
        } else {
            istringstream iss(line);
            string command;
            int row, col;
            iss >> command >> row >> col;

            c.type = CommandType::PLACE_BOMB;
            c.bombRow = row;
            c.bombCol = col;
        }

        commands.push_back(c);
    }

    // commands = [ POWER_UP, PLACE_BOMB(0,0), POWER_UP, PLACE_BOMB(1,1), POWER_DOWN, PLACE_BOMB(1,3) ]
    return commands;
}
