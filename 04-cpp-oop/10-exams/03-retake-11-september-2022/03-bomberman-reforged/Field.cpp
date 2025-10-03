//
// Created by tonytech on 3.10.2025.
//
#include "Field.h"
using namespace std;

Field::Field() = default;

auto Field::populateField(FieldData fieldData) -> void {
    const size_t rows = fieldData.size();
    const size_t cols = fieldData[0].size();

    _field.assign(rows, vector<int>(cols, 0));

    for (int row(0); row < fieldData.size(); row++) {
        for (int col(0); col < fieldData[row].size(); col++) {
            const int number = fieldData[row][col] - '0';
            this->_field[row][col] = number;
        }
    }
}

auto Field::getFieldData() -> std::vector<std::vector<int>> & { return this->_field; }
