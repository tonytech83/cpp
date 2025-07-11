//
// Created by tonytech on 29.6.2025.
//
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

auto main() -> int {
    string buff;
    getline(cin, buff);
    istringstream iss(buff);

    set<double> numbers;

    double number;
    while (iss >> number)
        numbers.insert(number);

    bool isFirst = true;
    for (const auto num: numbers) {
        if (!isFirst)
            cout << " <= ";

        cout << num;
        isFirst = false;
    }
    cout << endl;

    return 0;
}
