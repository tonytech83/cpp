//
// Created by tonytech on 13.7.2025.
//
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_SIZE = 6;

auto readMatrix(vector<vector<int>> &m, const int size) -> void {
    for (int r(0); r < size; ++r)
        for (int c(0); c < size; ++c)
            cin >> m[r][c];
}

auto findDiagonal(vector<pair<int, int>> &dCoordinates, const int size,
                  const bool isPrimary) -> void {
    if (isPrimary)
        for (int i(0); i < size; i++)
            dCoordinates.emplace_back(i, i);
    else
        for (int i(0); i < size; i++)
            dCoordinates.emplace_back(i, size - 1 - i);
}


auto checkCoordinates(const vector<pair<int, int>> &pD, const vector<pair<int, int>> &sD,
                      const pair<int, int> &coordinates) -> bool {
    for (const auto &pCoordinates: pD)
        if (pCoordinates == coordinates)
            return false;

    for (const auto &sCoordinates: sD)
        if (sCoordinates == coordinates)
            return false;

    return true;
}
auto printSum(const vector<vector<int>> &m, const vector<pair<int, int>> &pD, const vector<pair<int, int>> &sD,
              const int size) -> void {
    int sum = 0;

    for (int r(0); r < size; ++r)
        for (int c(0); c < size; ++c)
            if (checkCoordinates(pD, sD, {r, c}))
                if (m[r][c] % 2 == 1)
                    sum += m[r][c];

    cout << "The sum is: " << sum << endl;
}

auto main() -> int {
    int mSize;
    cin >> mSize;

    vector matrix(MAX_SIZE, vector<int>(MAX_SIZE));
    readMatrix(matrix, mSize);

    vector<pair<int, int>> primaryDiagonalCoordinates;
    vector<pair<int, int>> secondaryDiagonalCoordinates;
    findDiagonal(primaryDiagonalCoordinates, mSize, true);
    findDiagonal(secondaryDiagonalCoordinates, mSize, false);
    printSum(matrix, primaryDiagonalCoordinates, secondaryDiagonalCoordinates, mSize);

    return 0;
}