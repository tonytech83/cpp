//
// Created by tonytech on 02.07.2025.
//
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

auto fillPatternA(vector<vector<int>> &m) -> void {
    const int colSize = m.size();
    const int rowSize = colSize;

    int number = 0;
    for (auto col(0); col < colSize; col++)
        for (auto row(0); row < rowSize; row++) {
            number++;
            m[row][col] = number;
        }
}

auto fillPatternB(vector<vector<int>> &m) -> void {
    const int colSize = m.size();
    const int rowSize = colSize;

    int number = 0;
    for (auto col(0); col < colSize; col++) {
        if (col % 2 == 0) {
            for (auto row(0); row < rowSize; row++) {
                number++;
                m[row][col] = number;
            }
        } else {
            for (auto row(rowSize - 1); row >= 0; row--) {
                number++;
                m[row][col] = number;
            }
        }
    }
}

auto printMatrix(const vector<vector<int>> &m) -> void {
    for (auto &row: m) {
        for (const int col: row) {
            cout << col << ' ';
        }
        cout << endl;
    }
}

auto main() -> int {
    string line;
    getline(cin, line);

    istringstream iss(line);
    int N;
    char comma, pattern;
    iss >> N >> comma >> pattern;

    vector matrix(N, vector<int>(N));

    if (pattern == 'A')
        fillPatternA(matrix);
    else
        fillPatternB(matrix);

    printMatrix(matrix);

    return 0;
}
