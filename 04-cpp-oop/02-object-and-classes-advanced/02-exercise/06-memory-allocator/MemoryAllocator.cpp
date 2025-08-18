//
// Created by tonytech on 16.8.2025.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Defines.h"

using namespace std;

auto executeCommand(const string &command, vector<int *> &memory) -> ErrorCode {
    string action;
    int index = 0;
    istringstream iss(command);

    // Allocate
    if (command[0] == 'A') {
        iss >> action >> index;

        if (index >= memory.size())
            return INDEX_OUT_OF_BOUND;

        if (memory[index])
            return MEMORY_LEAK;

        memory[index] = new int;
        return EXECUTE_SUCCESS;
    }

    // Deallocate
    if (command[0] == 'D') {
        iss >> action >> index;
        if (index >= memory.size())
            return INDEX_OUT_OF_BOUND;

        if (memory[index]) {
            delete memory[index]; // frees the memory on the heap
            memory[index] = nullptr; // clears the pointer (good practice)
            return EXECUTE_SUCCESS;
        }

        return DOUBLE_FREE;
    }

    return EXECUTE_IDLE;
}

void printResult(const ErrorCode errorCode, const std::string &command) {
    string humanReadableError;
    switch (errorCode) {
        case 0:
            humanReadableError = "success";
            break;
        case 1:
            humanReadableError = "this exam is a piece of cake! Where is the OOP already?!?";
            break;
        case 2:
            humanReadableError = "memory leak prevented, will not make allocation";
            break;
        case 3:
            humanReadableError = "system crash prevented, will skip this deallocation";
            break;
        case 4:
            humanReadableError = "out of bound";
            break;
        default:
            break;
    }
    cout << command << " - " << humanReadableError << endl;
}
