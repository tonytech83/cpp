//
// Created by tonytech on 30.06.2025.
//
#include <iostream>
#include <vector>
using namespace std;

auto readMatrix(vector<vector<char>> &m) -> void {
    for (auto &row: m) {
        for (auto &col: row) {
            cin >> col;
        }
    }
}

auto findSquares(const vector<vector<char>> &m) -> int {
    int found = 0;
    for (int row(0); row < m.size() - 1; ++row)
        for (int col(0); col < m[row].size() - 1; ++col)
            if (m[row][col] == m[row + 1][col] && m[row][col] == m[row][col + 1] && m[row][col] == m[row + 1][col + 1])
                found++;

    return found;
}

auto main() -> int {
    int rowSize, colSize;
    cin >> rowSize >> colSize;

    vector matrix(rowSize, vector<char>(colSize));
    readMatrix(matrix);
    cout << findSquares(matrix) << endl;

    return 0;
}
