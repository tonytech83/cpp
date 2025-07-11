//
// Created by tonytech on 30.06.2025.
//
#include <array>
#include <iostream>
#include <sstream>
using namespace std;

constexpr int maxSize = 10;

auto readMatrix(istream &inputStream, array<array<int, maxSize>, maxSize> &m, int &rows, int &cols) -> void {
    inputStream >> rows;
    inputStream.ignore();

    for (int row(0); row < rows; row++) {
        string line;
        getline(cin, line);
        istringstream iss(line);

        int col = 0;
        while (iss >> m[row][col])
            col++;

        cols = col;
    }
}

auto compareMatrices(const array<array<int, maxSize>, maxSize> &m1, const array<array<int, maxSize>, maxSize> &m2,
                     const int &m1rows, const int &m1cols, const int &m2rows, const int &m2cols) -> bool {
    if (m1rows != m2rows || m1cols != m2cols)
        return false;

    for (int row(0); row < m1rows; row++)
        for (int col(0); col < m1cols; col++)
            if (m1[row][col] != m2[row][col])
                return false;

    return true;
}

auto main() -> int {

    array<array<int, maxSize>, maxSize> m1{}, m2{};

    int m1rows, m1cols, m2rows, m2cols;
    readMatrix(cin, m1, m1rows, m1cols);
    readMatrix(cin, m2, m2rows, m2cols);
    cout << (compareMatrices(m1, m2, m1rows, m1cols, m2rows, m2cols) ? "equal" : "not equal") << endl;

    return 0;
}
