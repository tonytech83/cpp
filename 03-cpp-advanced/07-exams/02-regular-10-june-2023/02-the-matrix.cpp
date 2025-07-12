//
// Created by tonytech on 12.7.2025.
//
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

constexpr int MAX_SIZE = 100;

void readMatrix(vector<vector<int>> &m, const int size) {
    for (int r = 0; r < size; r++) {
        for (int c(0); c < size; c++) {
            cin >> m[r][c];
        }
    }
}

auto isPrime(const int &number) -> bool {
    int divisorsCount = 0;
    for (int i(1); i <= number; i++) {
        if (number % i == 0)
            divisorsCount++;

        if (divisorsCount > 2)
            return false;
    }

    return true;
}

void printPrimeSumAboveDiagonals(const vector<vector<int>> &m, const int size) {
    int sum = 0;

    const int rowsToCheck = size / 2 + size % 2 + (size % 2 == 0 ? 1 : 0);

    int startCol = size % 2 + size / 2 - 1;
    int cols = startCol + ((size % 2 == 0) ? 2 : 1) - 1;
    for (int r(rowsToCheck); r < size; r++) {
        for (int c(startCol); c <= cols; c++) {
            if (isPrime(m[r][c]))
                sum += m[r][c];
        }
        cols++;
        startCol--;
    }

    cout << sum << endl;
}

auto main() -> int {
    int size;
    cin >> size;
    cin.ignore();

    vector matrix(MAX_SIZE, vector<int>(MAX_SIZE));
    readMatrix(matrix, size);
    printPrimeSumAboveDiagonals(matrix, size);

    return 0;
}
