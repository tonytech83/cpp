#include <iostream>
#include <string>
#include <vector>
#include "Defines.h"

auto executeCommand(const std::string &command, std::vector<int *> &memory) -> ErrorCode;

void printResult(const ErrorCode errorCode, const std::string &command);

auto main() -> int {
    std::string command;
    int memorySize = 0;
    int inputSize = 0;
    std::vector<int *> memory;

    std::cin >> memorySize >> inputSize;
    std::cin.ignore();

    memory.resize(memorySize, nullptr);

    for (int i = 0; i < inputSize; ++i) {
        getline(std::cin, command);

        const ErrorCode errorCode = executeCommand(command, memory);

        printResult(errorCode, command);
    }

    return 0;
}
