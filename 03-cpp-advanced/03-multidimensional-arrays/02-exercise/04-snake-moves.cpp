//
// Created by tonytech on 30.06.2025.
//
#include <iostream>
#include <vector>
using namespace std;

constexpr int maxFieldSize = 12;

auto printSnakeMoves(char f[][maxFieldSize], const int rows, const int cols) -> void {
    for (auto row(0); row < rows; row++) {
        for (auto col(0); col < cols; col++)
            cout << f[row][col];
        cout << endl;
    }
}

auto main() -> int {
    int rows, cols;
    string snake;
    cin >> rows >> cols >> snake;

    char field[maxFieldSize][maxFieldSize];

    int direction = 1;
    int col = 0;
    auto itS = snake.begin();
    for (auto row(0); row < rows;) {
        field[row][col] = *itS;

        ++itS; // next symbol form snake

        if (itS == snake.end())
            itS = snake.begin(); // reset the snake - start from begin

        col += direction;

        if (direction > 0) {
            // filling even row
            if (col >= cols) {
                row++;
                direction = -1;
                col = cols - 1;
            }
        } else {
            if (col < 0) {
                // the row is full, go to next row
                row++;
                direction = 1;
                col = 0;
            }
        }
    }

    printSnakeMoves(field, rows, cols);

    return 0;
}
