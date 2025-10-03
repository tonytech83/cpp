//
// Created by tonytech on 3.10.2025.
//

#include "BomberMan.h"

auto findStartAndEnd(const std::size_t &size, const int &bombPower, int &start, int &end) -> void {
    start = start - bombPower;
    if (start < 0)
        start = 0;

    end = end + bombPower;
    if (end >= size)
        end = size - 1;
}

BomberMan::BomberMan() = default;

auto BomberMan::bombPowerUp() -> void { this->_bombPower++; }

auto BomberMan::bombPowerDown() -> void {
    this->_bombPower--;
    if (this->_bombPower < 0)
        this->_bombPower = 0;
}

auto BomberMan::getBombPower() const -> int { return this->_bombPower; }


auto BomberMan::placeBomb(std::vector<std::vector<int>> &fieldData, const int &bombRow, const int &bombCol) -> int {
    int currScore = 0;

    // Horizontal
    int colStart = bombCol, colEnd = bombCol;
    findStartAndEnd(fieldData[bombRow].size(), this->_bombPower, colStart, colEnd);

    for (int col = colStart; col <= colEnd; col++) {
        const int points = fieldData[bombRow][col];
        currScore += points;
        fieldData[bombRow][col] = 0;
    }

    // Vertical
    int rowStart = bombRow, rowEnd = bombRow;
    findStartAndEnd(fieldData.size(), this->_bombPower, rowStart, rowEnd);

    for (int row = rowStart; row <= rowEnd; row++) {
        const int points = fieldData[row][bombCol];
        currScore += points;
        fieldData[row][bombCol] = 0;
    }

    return currScore;
}
