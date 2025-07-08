//
// Created by tonytech on 8.7.2025.
//
#include <iostream>
#include <memory>
#include <sstream>
using namespace std;

auto printField(shared_ptr<shared_ptr<char[]>[]> mineField, int rows, int cols) -> void {
    cout << "--------------- Debug start -------------------" << endl;
     for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            cout << mineField[r][c];

        cout << endl;
    }

    cout << "--------------- Debug end -------------------" << endl;
}

auto main() -> int {
    int rows, cols;
    cin >> rows >> cols;

    // array of shared pointers, which one pointing to an array of shared pointers
    shared_ptr<shared_ptr<char[]>[]> mineField(new shared_ptr<char[]>[rows]);

    for (int r = 0; r < rows; r++) {
        mineField[r] = shared_ptr<char[]>(new char[cols]);

        for (int c = 0; c < cols; c++) {
            cin >> mineField[r][c];
        }
    }

    // Debug
    // printField(mineField, rows, cols);


    return 0;
}
