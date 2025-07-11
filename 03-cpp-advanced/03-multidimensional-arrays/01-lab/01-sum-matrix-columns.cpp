//
// Created by tonytech on 29.6.2025.
//
#include <iostream>
#include <vector>
using namespace std;

auto fillMatrix(vector<vector<int>> &matrix ) -> void {
    for (auto & row : matrix)
        for (auto & col : row)
            cin >> col;
}

auto sumMatrixColumns(const vector<vector<int>> &matrix) -> vector<int> {
    const size_t rowSize = matrix.size();
    const size_t colSize = matrix[0].size();
    vector<int> result(colSize);

    for (auto row(0); row < rowSize; row++)
        for (auto col(0); col < colSize; col++)
            result[col] += matrix[row][col];

    return result;
}

auto main() -> int {
    int rowSize, colSize;
    cin >> rowSize >> colSize;

    vector matrix(rowSize, vector<int>(colSize));

    fillMatrix(matrix);
    const vector<int> sums = sumMatrixColumns(matrix);

    for (const auto sum: sums)
        cout << sum << endl;

    return 0;
}
