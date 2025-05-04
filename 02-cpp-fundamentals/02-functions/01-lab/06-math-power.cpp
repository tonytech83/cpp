//
// Created by tonytech on 5/4/25.
//
#include <iostream>
using namespace std;

int mathPower(int x, int y);

int main() {
    int number, power;
    cin >> number >> power;

    cout << mathPower(number, power) << endl;

    return 0;
}

int mathPower(const int x, const int y) {
    int result = 1;
    for (int i = 1; i <= y; i++) {
        result *= x;
    }

    return result;
}
