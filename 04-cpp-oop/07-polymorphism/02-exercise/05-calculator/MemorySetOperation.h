//
// Created by tonytech on 16.09.2025.
//

#ifndef CPP_MEMORYSETOPERAION_H
#define CPP_MEMORYSETOPERAION_H

#include <stack>
#include "Operation.h"

class MemorySetOperation final : public Operation {
public:
    std::stack<int> memory;

    auto addOperand(const int operand) -> void override { memory.push(operand); }

    auto getResult() -> int override {
        if (memory.empty())
            return 0;

        const int top = memory.top();
        memory.pop();
        return top;
    }
    auto isCompleted() -> bool override { return false; }
};

#endif // CPP_MEMORYSETOPERAION_H
