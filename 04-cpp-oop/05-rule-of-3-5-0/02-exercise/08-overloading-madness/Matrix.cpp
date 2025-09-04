//
// Created by tonytech on 04.09.2025.
//

#include "Matrix.h"
#include <sstream>
using namespace std;

auto Matrix::operator=(const std::vector<std::vector<int>> &data) -> Matrix & {
    this->_data = data;

    return *this;
}

auto Matrix::operator+=(const Matrix &other) -> Matrix & {
    // on condition right matrix is smaller
    const int size = static_cast<int>(other._data.size());
    for (int row(0); row < size; ++row)
        for (int col(0); col < size; ++col)
            this->_data[row][col] += other._data[row][col];

    return *this;
}

auto Matrix::operator-=(const Matrix &other) -> Matrix & {
    const int size = static_cast<int>(other._data.size());
    for (int row(0); row < size; ++row)
        for (int col(0); col < size; ++col)
            this->_data[row][col] -= other._data[row][col];

    return *this;
}

auto Matrix::operator*=(const Matrix &other) -> Matrix & {
    const int size = static_cast<int>(other._data.size());
    for (int row(0); row < size; ++row)
        for (int col(0); col < size; ++col)
            this->_data[row][col] *= other._data[row][col];

    return *this;
}

auto Matrix::operator/=(const Matrix &other) -> Matrix & {
    const int size = static_cast<int>(other._data.size());
    for (int row(0); row < size; ++row)
        for (int col(0); col < size; ++col) {
            if (other._data[row][col] != 0)
                this->_data[row][col] /= other._data[row][col];
            else
                this->_data[row][col] = 0;
        }

    return *this;
}

auto operator<<(std::ostream &os, const Matrix &matrix) -> ostream & {
    for (int row(0); row < matrix._data.size(); ++row) {
        for (int col(0); col < matrix._data.size(); ++col)
            os << matrix._data[row][col] << ' ';

        os << endl;
    }

    return os;
}
