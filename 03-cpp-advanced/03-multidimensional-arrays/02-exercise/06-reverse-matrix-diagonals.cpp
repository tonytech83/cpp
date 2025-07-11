//
// Created by tonytech on 30.06.2025.
//

#include <iostream>
#include <vector>
using namespace std;

auto readMatrix(vector<vector<int>> &m) -> void {
    for (auto &row: m)
        for (auto &col: row)
            cin >> col;
}

auto printRightDiagonal(const vector<vector<int>> &m, const int startRow, const int startCol) -> void {
    const int lastCol = m[0].size() - 1;

    for (int row = startRow, col = startCol; row >= 0 && col <= lastCol; row--, col++)
        cout << m[row][col] << ' ';

    cout << endl;
}

auto main() -> int {
    int rows, cols;
    cin >> rows >> cols;

    vector matrix(rows, vector<int>(cols));
    readMatrix(matrix);

    for (int col = matrix[0].size() - 1; col >= 0; col--)
        printRightDiagonal(matrix, matrix.size() - 1, col);

    for (int row = matrix.size() - 2; row >= 0; row--)
        printRightDiagonal(matrix, row, 0);


    return 0;
}
