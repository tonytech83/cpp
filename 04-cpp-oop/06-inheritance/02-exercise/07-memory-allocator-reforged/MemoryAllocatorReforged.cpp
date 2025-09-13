//
// Created by tonytech on 13.9.2025.
//

#include <iostream>
#include <sstream>
#include <vector>
#include "Defines.h"
using namespace std;

class Command {
protected:
    vector<MemoryNode> &memory;
    static int AllocatedMemory;

public:
    explicit Command(vector<MemoryNode> &memory) : memory(memory) {}
};

int Command::AllocatedMemory = 0;

class MemoryTypeCommand : public Command {
protected:
    MemoryType mt;
    int index{};

public:
    MemoryTypeCommand(vector<MemoryNode> &memory, istream &iss) : Command(memory) {
        string mType;

        iss >> mType >> this->index;
        this->mt = (mType[0] == 'S' ? MemoryType::SINGLE : MemoryType::MULTIPLE);
    }

    virtual auto execute() -> ErrorCode { return EXECUTE_SUCCESS; }

    virtual ~MemoryTypeCommand() = default;
};

class AllocateCommand final : public MemoryTypeCommand {
public:
    AllocateCommand(vector<MemoryNode> &memory, istream &iss) : MemoryTypeCommand(memory, iss) {}

    auto execute() -> ErrorCode override {
        if (memory[index].rawMemory != nullptr)
            return MEMORY_LEAK;

        memory[index].memoryType = this->mt;
        memory[index].rawMemory = &AllocatedMemory;

        return EXECUTE_SUCCESS;
    }
};

class DeallocateCommand final : public MemoryTypeCommand {
public:
    DeallocateCommand(vector<MemoryNode> &memory, istream &iss) : MemoryTypeCommand(memory, iss) {}

    auto execute() -> ErrorCode override {
        if (memory[index].rawMemory == nullptr)
            return DOUBLE_FREE;

        if (memory[index].memoryType != this->mt)
            return ALLOCATE_DEALLOCATE_MISMATCH;

        memory[index].memoryType = UNKNOWN;
        memory[index].rawMemory = nullptr;
        return EXECUTE_SUCCESS;
    }
};

ErrorCode executeCommand(const string &command, vector<MemoryNode> &memory) {
    istringstream iss(command);
    string action;
    iss >> action;

    switch (action[0]) {
        case 'A':
            return AllocateCommand(memory, iss).execute();
        case 'D':
            return DeallocateCommand(memory, iss).execute();
        default:
            break;
    }

    return EXECUTE_SUCCESS;
}

void printResult(const ErrorCode errorCode, const string &command) {
    ostringstream output;
    output << command << " - ";

    switch (errorCode) {
        case EXECUTE_SUCCESS:
            output << "success";
            break;
        case MEMORY_LEAK:
            output << "memory leak prevented, will not make allocation";
            break;
        case DOUBLE_FREE:
            output << "system crash prevented, will skip this deallocation";
            break;
        case ALLOCATE_DEALLOCATE_MISMATCH:
            output << "Warning allocate/deallocate mismatch, will skip this deallocation";
            break;
        default:
            break;
    }

    cout << output.str() << endl;
}
