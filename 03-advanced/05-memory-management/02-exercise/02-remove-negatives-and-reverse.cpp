//
// Created by tonytech on 08.07.2025.
//
#include <iostream>
#include <memory>
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

auto readIntArray(istream &istr, size_t &size) -> shared_ptr<int[]> {
    string line;
    getline(istr, line);
    istringstream iss(line);

    size = countTokens(line);
    shared_ptr<int[]> numbers(new int[size]);

    int count = 0;
    while (iss >> numbers[count]) {
        count++;
    }

    return numbers;
}

auto main() -> int {
    size_t size = 0;
    const shared_ptr<int[]> numbers = readIntArray(cin, size);

    bool notEmpty = false;
    for (int i = static_cast<int>(size) - 1; i >= 0; i--)
        if (numbers[i] >= 0) {
            notEmpty = true;
            cout << numbers[i] << ' ';
        }
    if (!notEmpty)
        cout << "empty" << endl;

    cout << endl;
    return 0;
}
