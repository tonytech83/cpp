//
// Created by tonytech on 8.7.2025.
//
#include <iostream>
#include <memory>
#include <sstream>
using namespace std;

auto printField(const shared_ptr<shared_ptr<int[]>[]> &mineField, const int rows, const int cols) -> void {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            cout << mineField[r][c];

        cout << endl;
    }
}

auto readField(shared_ptr<shared_ptr<char[]>[]> &f, const int rows, const int cols) -> void {
    for (int r = 0; r < rows; r++) {
        f[r] = shared_ptr<char[]>(new char[cols]);

        for (int c = 0; c < cols; c++) {
            cin >> f[r][c];
        }
    }
}

auto zeroInitialization(shared_ptr<shared_ptr<int[]>[]> &f, const int rows, const int cols) -> void {
    for (int r = 0; r < rows; r++) {
        f[r] = shared_ptr<int[]>(new int[cols]);
        for (int c = 0; c < cols; c++)
            f[r][c] = 0;
    }
}

auto isInside(const int rows, const int cols, const int r, const int c) -> bool {
    if (r >= 0 && r < rows && c >= 0 && c < cols)
        return true;

    return false;
}


auto sweep(const shared_ptr<shared_ptr<char[]>[]> &mF, shared_ptr<shared_ptr<int[]>[]> &sF, const int rows,
           const int cols) -> void {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (mF[r][c] == '!') {
                if (isInside(rows, cols, r - 1, c - 1))
                    sF[r - 1][c - 1]++;
                if (isInside(rows, cols, r - 1, c))
                    sF[r - 1][c]++;
                if (isInside(rows, cols, r - 1, c + 1))
                    sF[r - 1][c + 1]++;
                if (isInside(rows, cols, r, c - 1))
                    sF[r][c - 1]++;
                if (isInside(rows, cols, r, c))
                    sF[r][c]++;
                if (isInside(rows, cols, r, c + 1))
                    sF[r][c + 1]++;
                if (isInside(rows, cols, r + 1, c - 1))
                    sF[r + 1][c - 1]++;
                if (isInside(rows, cols, r + 1, c))
                    sF[r + 1][c]++;
                if (isInside(rows, cols, r + 1, c + 1))
                    sF[r + 1][c + 1]++;
            }
}

auto main() -> int {
    int rows, cols;
    cin >> rows >> cols;

    // array of shared pointers, which one is pointing to an array of shared pointers
    shared_ptr<shared_ptr<char[]>[]> mineField(new shared_ptr<char[]>[rows]);
    shared_ptr<shared_ptr<int[]>[]> sweepedField(new shared_ptr<int[]>[rows]);

    zeroInitialization(sweepedField, rows, cols);

    readField(mineField, rows, cols);
    sweep(mineField, sweepedField, rows, cols);

    printField(sweepedField, rows, cols);

    return 0;
}
