//
// Created by tonytech on 5/6/25.
//

#include <iostream>
using namespace std;

bool getDigit(int n, int &s);

int main() {
    int n;
    cin >> n;

    int sumOfEvens = 0;
    int sumOfOdds = 0;

    while (n) {
        int single;

        if (getDigit(n, single)) {
            sumOfEvens += single;
        } else {
            sumOfOdds += single;
        }
        n /= 10;
    }

    cout << sumOfEvens * sumOfOdds << endl;

    return 0;
}

bool getDigit(const int n, int &s) {
    s = n % 10;

    return s % 2 == 0;
}
