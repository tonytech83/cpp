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

auto printMatrix(const vector<vector<char>> &m, const int size) -> void {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

auto isInside(const int size, const int r, const int c) -> bool {
    if (r >= 0 && r < size && c >= 0 && c < size)
        return true;

    return false;
}

auto doRust(vector<vector<char>> &m, const int size) -> void {
    for (int r = 0; r < size; r++) {
        bool stop = false;
        for (int c = 0; c < size; c++) {
            if (m[r][c] == '!') {
                if (isInside(size, r - 1, c) && m[r - 1][c] != '#')
                    m[r - 1][c] = '!';
                if (isInside(size, r + 1, c) && m[r + 1][c] != '#')
                    m[r + 1][c] = '!';
                if (isInside(size, r, c - 1) && m[r][c - 1] != '#')
                    m[r][c - 1] = '!';
                if (isInside(size, r, c + 1) && m[r][c + 1] != '#')
                    m[r][c + 1] = '!';
                stop = true;
                break;

            }
        }
        if (stop)
            break;
    }
    printMatrix(m, size);
    cout << "=================================" <<  endl;
}

auto main() -> int {
    vector<vector<char>> matrix;
    readMatrix(cin, matrix, matrixSize);

    int units;
    cin >> units;
    while (units--)
        doRust(matrix, matrixSize);

    // printMatrix(matrix, matrixSize);

    return 0;
}
