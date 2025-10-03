//
// Created by tonytech on 3.10.2025.
//

#ifndef CPP_FIELD_H
#define CPP_FIELD_H

#include <vector>


#include "Defines.h"


class Field {
    std::vector<std::vector<int>> _field;

public:
    Field();

    auto populateField(FieldData fieldData) -> void;

    auto getFieldData() -> std::vector<std::vector<int>> &;
};

#endif // CPP_FIELD_H
