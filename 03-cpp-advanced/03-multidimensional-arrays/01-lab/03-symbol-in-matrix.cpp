//
// Created by tonytech on 29.6.2025.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

auto fillMatrix(vector<vector<char>> &matrix) -> void {
    for (auto &row: matrix) {
        string rowLine;
        getline(cin, rowLine);

        for (auto col(0); col < rowLine.size(); ++col)
            row[col] = rowLine[col];
    }
}

auto main() -> int {
    int N;
    cin >> N;
    cin.ignore();

    vector squareMatrix(N, vector<char>(N));
    fillMatrix(squareMatrix);

    char symbol;
    cin >> symbol;

    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < N; ++j)
            if (squareMatrix[i][j] == symbol) {
                cout << '(' << i << ", " << j << ')' << endl;
                return 0;
            }
    cout << symbol << " does not occur in the matrix" << endl;

    return 0;
}
