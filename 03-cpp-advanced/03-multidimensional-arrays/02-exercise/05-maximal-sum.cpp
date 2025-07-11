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

auto maxSumSquare(const vector<vector<int>> &m) -> void {
    int maxSum = 0;
    int rowMax = 0;
    int colMax = 0;

    for (auto row(0); row < m.size() - 2; row++) {
        for (auto col(0); col < m[row].size() - 2; col++) {
            int currSum = 0;
            currSum += m[row][col] + m[row][col + 1] + m[row][col + 2] + m[row + 1][col] + m[row + 1][col + 1] +
                       m[row + 1][col + 2] + m[row + 2][col] + m[row + 2][col + 1] + m[row + 2][col + 2];

            if (currSum > maxSum) {
                rowMax = row;
                colMax = col;
                maxSum = currSum;
            }
        }
    }

    cout << "Sum = " << maxSum << endl;
    for (int row(rowMax); row < rowMax + 3; row++) {
        for (int col(colMax); col < colMax + 3; col++) {
            cout << m[row][col] << ' ';
        }
        cout << endl;
    }
}

auto main() -> int {
    int N, M;
    cin >> N >> M;
    cin.ignore();

    vector matrix(N, vector<int>(M));
    readMatrix(matrix);
    maxSumSquare(matrix);

    return 0;
}
