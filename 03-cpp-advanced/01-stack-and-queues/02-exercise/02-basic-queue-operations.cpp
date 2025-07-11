//
// Created by tonytech on 6/21/25.
//
#include <iostream>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;

int searchForX(queue<int> que, const int value) {
    int minNumber = INT_MAX;
    while (!que.empty()) {
        const int currentNumber = que.front();
        que.pop();

        if (currentNumber == value)
            return currentNumber;

        if (currentNumber < minNumber)
            minNumber = currentNumber;
    }

    return minNumber;
}

int main() {
    int N, S, X;
    cin >> N >> S >> X;

    queue<int> numbers;

    while (N--) {
        int number;
        cin >> number;
        numbers.push(number);
    }

    while (S--) {
        numbers.pop();
    }

    if (numbers.empty()) {
        cout << '0' << endl;
        return 0;
    }

    int result = searchForX(numbers, X);
    if (result == X)
        cout << "true" << endl;
    else
        cout << result << endl;

    return 0;
}