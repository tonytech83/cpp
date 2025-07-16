//
// Created by tonytech on 16.07.2025.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

constexpr int CHESS_SIZE = 8;

void readBoard(vector<vector<char>> &b, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> b[i][j];
        }
    }
}

auto printFigures(const vector<char> &figures, const char color) -> void {
    if (figures.empty() && color == 'w') {
        cout << "<no white figures>";
    } else if (figures.empty() && color == 'b')
        cout << "<no black figures>";
    else
        for (const char c: figures)
            cout << c;
        cout << endl;
}

auto reverseColorAndPrint(const vector<vector<char>> &b, const int size) -> void {
    vector<char> white;
    vector<char> black;
    vector revertedBoard(size, vector<char>(size));


    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (isupper(b[i][j])) {
                white.push_back(b[i][j]);
                revertedBoard[i][j] = tolower(b[i][j]);
            } else if (islower(b[i][j])) {
                black.push_back(b[i][j]);
                revertedBoard[i][j] = toupper(b[i][j]);
            } else
                revertedBoard[i][j] = b[i][j];
        }
    }

    printFigures(white, 'w');
    printFigures(black, 'b');

    for (int r(0); r < size; r++) {
        for (int c(0); c < size; c++)
            cout << revertedBoard[r][c];
        cout << endl;
    }
}

auto main() -> int {
    vector chessBoard(CHESS_SIZE, vector<char>(CHESS_SIZE));
    readBoard(chessBoard, CHESS_SIZE);
    reverseColorAndPrint(chessBoard, CHESS_SIZE);

    return 0;
}
