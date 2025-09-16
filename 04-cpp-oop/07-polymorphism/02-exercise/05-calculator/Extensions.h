//
// Created by tonytech on 16.09.2025.
//

#ifndef CPP_EXTENSIONS_H
#define CPP_EXTENSIONS_H

#include "AdvancedInputInterpreter.h"
#include "InputInterpreter.h"

inline auto buildInterpreter(CalculationEngine &engine) -> std::shared_ptr<InputInterpreter> {
    return std::make_shared<AdvancedInputInterpreter>(engine);
}

#endif // CPP_EXTENSIONS_H
