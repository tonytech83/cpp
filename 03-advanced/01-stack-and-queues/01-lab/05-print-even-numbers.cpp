//
// Created by tonytech on 17.06.2025.
//
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string integers;
    getline(cin, integers);
    istringstream iss(integers);

    queue<int> numbers;

    int number;
    while (iss >> number)
        numbers.push(number);


    while (numbers.size() != 1) {
        if (numbers.front() % 2 == 0)
            cout << numbers.front() << ", ";

        numbers.pop();
    }
    if (numbers.front() % 2 == 0)
        cout << numbers.front();
    cout << endl;

    return 0;
}
