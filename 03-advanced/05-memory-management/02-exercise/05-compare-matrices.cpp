//
// Created by tonytech on 08.07.2025.
//
#include <iostream>
#include <sstream>
using namespace std;

auto countTokens(const string &line) -> size_t {
    size_t tokens = 0;

    istringstream iss(line);
    string token;
    while (iss >> token)
        tokens++;

    return tokens;
}

auto readMatrix(istream &in, int **&matrix, int &rows, int &cols) -> void {
    in >> rows;
    in.ignore();

    matrix = new int *[rows];

    cols = 0;
    for (int r = 0; r < rows; r++) {
        string currRow;
        getline(in, currRow);
        cols = static_cast<int>(countTokens(currRow));

        matrix[r] = new int[cols];
        istringstream iss(currRow);

        for (int c = 0; c < cols; c++)
            iss >> matrix[r][c];
    }
}

auto deleteMatrix(int **matrix, const int &rows) -> void {
    for (int r = 0; r < rows; r++)
        delete[] matrix[r];
    delete[] matrix;
}

auto printMatrix(int **matrix, const int &rows, const int &cols) -> void {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            cout << matrix[r][c] << ' ';
        cout << endl;
    }
}

auto compareMatrices(int **m1, int **m2, const int m1r, const int m1c, const int m2r, const int m2c) -> bool {
    if (m1r != m2r || m1c != m2c)
        return false; // not equal dimensions

    for (int r = 0; r < m1r; r++)
        for (int c = 0; c < m1c; c++)
            if (m1[r][c] != m2[r][c])
                return false; // we found at least one ono-equal element

    return true; // matrices are equal
}

auto main() -> int {
    int m1rows, m1cols, m2rows, m2cols;

    // pointer to pointer => 2D array
    int **matrix1, **matrix2;

    readMatrix(cin, matrix1, m1rows, m1cols);
    readMatrix(cin, matrix2, m2rows, m2cols);

    // Debug
    // printMatrix(matrix1, m1rows, m1cols);
    // printMatrix(matrix2, m2rows, m2cols);


    cout << (compareMatrices(matrix1, matrix2, m1rows, m1cols, m2rows, m2cols) ? "equal" : "not equal") << endl;

    deleteMatrix(matrix1, m1rows);
    deleteMatrix(matrix2, m2rows);

    return 0;
}
