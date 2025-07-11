//
// Created by tonytech on 29.6.2025.
//
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

auto main () -> int {
    string buff;
    getline(cin, buff);
    istringstream iss(buff);

    vector<int> numbers;

    int number;
    while (iss >> number) {
        if (sqrt(number) == floor(sqrt(number)))
            numbers.push_back(number);
    }

    sort(numbers.begin(), numbers.end(), greater<>());
    for (const auto num: numbers)
        cout << num << ' ';

    cout << endl;

    return 0;
}