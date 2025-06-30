//
// Created by tonytech on 30.06.2025.
//
#include <iostream>
#include <vector>
using namespace std;


auto readMatrix(vector<vector<int>> &m) -> void {
    for (auto &row : m) {
        for (auto &col : row) {
            cin >> col;
        }
    }
}

auto findPosition(vector<vector<int>> &m, const int &num) -> void {
    bool found = false;
    for (int row(0); row < m.size(); row++)
        for (int col(0); col < m[row].size(); col++)
            if (m[row][col] == num) {
                found = true;
                cout << row << " " << col << endl;
            }

    if (!found)
        cout << "not found" << endl;
}

auto main () -> int {
    int R, C;
    cin >> R >> C;
    cin.ignore();

    vector matrix(R, vector<int>(C));
    readMatrix(matrix);

    int number;
    cin >> number;

    findPosition(matrix, number);

    return 0;
}