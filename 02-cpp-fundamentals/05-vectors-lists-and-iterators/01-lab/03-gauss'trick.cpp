//
// Created by tonytech on 5/25/25.
//
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> readNumbers(const string &str) {
    vector<int> numbers;
    istringstream iss(str);

    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }

    return numbers;
}

int main() {
    string buffer;
    getline(cin, buffer);

    vector<int> numbers = readNumbers(buffer);

    vector<int> sums;
    const int iterations = numbers.size() / 2;

    for (int i = 0; i < iterations; i++) {
        const int first = numbers.front();
        const int last = numbers.back();
        numbers.pop_back();
        numbers.erase(numbers.begin());


        sums.push_back(first + last);
    }

    if (!numbers.empty()) {
        sums.push_back(numbers.front());
    }

    for (const int sum: sums) {
        cout << sum << ' ';
    }

    cout << endl;

    return 0;
}
