//
// Created by tonytech on 5/1/25.
//

#include <iostream>
using namespace std;

int factorial(const int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int N;
    cin >> N;

    int strongSum = 0;

    int remainingN = N;
    while (remainingN) {
        const int currDigit = remainingN % 10;
        remainingN /= 10;
        strongSum += factorial(currDigit);
    }

    cout << (strongSum == N ? "yes" : "no") << endl;

    return 0;
}
