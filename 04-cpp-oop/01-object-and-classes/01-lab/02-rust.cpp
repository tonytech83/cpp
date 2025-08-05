//
// Created by tonytech on 10.07.2025.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

constexpr int matrixSize = 10;

auto readMatrix(istream &in, vector<vector<char>> &m, int lines) -> void {
    while (lines--) {
        string line;
        getline(in, line);
        istringstream iss(line);
        vector<char> row;

        char c;
        while (iss >> c)
            row.push_back(c);

        m.push_back(row);
    }
}

auto isInside(const int size, const int r, const int c) -> bool {
    if (r >= 0 && r < size && c >= 0 && c < size)
        return true;

    return false;
}

auto printMatrix(const vector<vector<char>> &m, const int size) -> void {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

auto doRust(vector<vector<char>> &m, const int size) -> void {
    const vector<vector<char>> temp = m;

    // Directions
    const int dR[4] = {-1, 1, 0, 0};
    const int dC[4] = {0, 0, -1, 1};

    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            if (temp[r][c] == '!')
                for (int d(0); d < 4; d++) {
                    const int nr = r + dR[d];
                    const int nc = c + dC[d];
                    if (isInside(size, nr, nc) && m[nr][nc] != '#')
                        m[nr][nc] = '!';
                }
}

auto main() -> int {
    vector<vector<char>> matrix;
    readMatrix(cin, matrix, matrixSize);

    int units;
    cin >> units;
    while (units--)
        doRust(matrix, matrixSize);

    printMatrix(matrix, matrixSize);

    return 0;
}
