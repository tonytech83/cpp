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

auto primaryDiagonalSum(const vector<vector<int>> &matrix, const int size) -> int {
    int sum = 0;

    for (auto i(0); i < size; i++)
        sum += matrix[i][i];

    return sum;
}

auto main() -> int {
    int N;
    cin >> N;

    vector squareMatrix (N, vector<int>(N));
    fillMatrix(squareMatrix);

    cout << primaryDiagonalSum(squareMatrix, N) << endl;
    return 0;
}