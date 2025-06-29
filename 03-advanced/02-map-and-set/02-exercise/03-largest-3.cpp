//
// Created by tonytech on 29.6.2025.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;


auto main() -> int {
    string buff;
    getline(cin, buff);
    istringstream iss(buff);

    set<double, greater<>> numbers;

    double number;
    while (iss >> number) {
        numbers.insert(number);
    }

    int counter = 3;
    for (const auto num : numbers) {
        cout << num << ' ';
        if (--counter == 0)
            break;
    }


    return 0;
}
