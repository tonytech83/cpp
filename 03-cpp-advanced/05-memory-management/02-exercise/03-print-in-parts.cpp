//
// Created by tonytech on 08.07.2025.
//
#include <iostream>
#include <memory>
using namespace std;

auto main() -> int {
    int rows, cols;
    cin >> rows >> cols;

    // Representing the matrix in 1-dimensional array
    // if we have 3 rows and 4 columns, the new array should be with size of 3 * 4 = 12
    // the element index will be equal to (row * cols + col)
    unique_ptr<int[]> matrix(new int[rows * cols]);

    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            cin >> matrix[row * cols + col];

    int sub_rows, sub_cols;
    cin >> sub_rows >> sub_cols;

    for (int row = 0; row < sub_rows; row++) {
        for (int col = 0; col < sub_cols; col++)
            cout << matrix[row * cols + col] << ' ';
        cout << endl;
    }

    return 0;
}
