//
// Created by tonytech on 10.07.2025.
//
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

constexpr int MATRIX_SIZE = 10;

class Matrix {
    vector<vector<char>> matrix;

public:
    explicit Matrix(const int &size) { readMatrix(cin, size); }

private:
    auto readMatrix(istream &in, int lines) -> void {
        while (lines--) {
            string line;
            getline(in, line);
            istringstream iss(line);
            vector<char> row;

            char c;
            while (iss >> c)
                row.push_back(c);

            this->matrix.push_back(row);
        }
    }

    static auto isInside(const int r, const int c) -> bool {
        if (r >= 0 && r < MATRIX_SIZE && c >= 0 && c < MATRIX_SIZE)
            return true;

        return false;
    }

public:
    [[nodiscard]] auto print() const -> string {
        ostringstream oss;
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                oss << this->matrix[i][j];
            }
            oss << endl;
        }
        return oss.str();
    }

    auto doRust() -> void {
        const vector<vector<char>> temp = this->matrix;

        // Directions
        const int dR[4] = {-1, 1, 0, 0};
        const int dC[4] = {0, 0, -1, 1};

        for (int r = 0; r < MATRIX_SIZE; r++)
            for (int c = 0; c < MATRIX_SIZE; c++)
                if (temp[r][c] == '!')
                    for (int d(0); d < 4; d++) {
                        const int nr = r + dR[d];
                        const int nc = c + dC[d];
                        if (isInside(nr, nc) && this->matrix[nr][nc] != '#')
                            this->matrix[nr][nc] = '!';
                    }
    }
};

auto main() -> int {
    Matrix m(MATRIX_SIZE);

    size_t units;
    cin >> units;
    while (units--)
        m.doRust();

    cout << m.print() << endl;

    return 0;
}
