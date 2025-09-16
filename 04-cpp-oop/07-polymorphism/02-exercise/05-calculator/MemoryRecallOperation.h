//
// Created by tonytech on 16.09.2025.
//

#ifndef CPP_MEMORYRECALLOPERATION_H
#define CPP_MEMORYRECALLOPERATION_H

#include <memory>
#include <utility>
#include "MemorySetOperation.h"

class MemoryRecallOperation final : public Operation {
    std::shared_ptr<MemorySetOperation> ms;

public:
    explicit MemoryRecallOperation(std::shared_ptr<MemorySetOperation> ms) : ms(std::move(ms)) {}

    auto addOperand(int operand) -> void override {}
    auto getResult() -> int override { return ms->getResult(); }
    auto isCompleted() -> bool override { return true; }
};

#endif // CPP_MEMORYRECALLOPERATION_H
