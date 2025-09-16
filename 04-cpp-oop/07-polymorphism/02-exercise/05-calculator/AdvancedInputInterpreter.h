//
// Created by tonytech on 16.09.2025.
//

#ifndef CPP_ADVANCEDINPUTINTERPRETER_H
#define CPP_ADVANCEDINPUTINTERPRETER_H

#include "DivisionOperation.h"
#include "InputInterpreter.h"
#include "MemoryRecallOperation.h"
#include "MemorySetOperation.h"

class AdvancedInputInterpreter : public InputInterpreter {
    std::shared_ptr<MemorySetOperation> ms;

public:
    explicit AdvancedInputInterpreter(CalculationEngine &engine) :
        InputInterpreter(engine), ms(new MemorySetOperation()) {}

    auto getOperation(const std::string operation) -> std::shared_ptr<Operation> override {
        if (operation == "/")
            return std::make_shared<DivisionOperation>();

        if (operation == "ms")
            // return std::make_shared<MemorySetOperation>();
            return ms;

        if (operation == "mr")
            return std::make_shared<MemoryRecallOperation>(ms);

        return InputInterpreter::getOperation(operation);
    }
};

#endif // CPP_ADVANCEDINPUTINTERPRETER_H
