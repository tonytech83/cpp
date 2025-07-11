//
// Created by tonytech on 6/21/25.
//
#include <iostream>
#include <stack>
#include <climits>
using namespace std;

int searchForX(stack<int> stck, const int value) {
    int minNumber = INT_MAX;
    while (!stck.empty()) {
        const int currentNumber = stck.top();
        stck.pop();

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

    stack<int> numbers;

    // read and push N elements
    while (N--) {
        int num;
        cin >> num;
        numbers.push(num);
    }

    // pop S elements
    while (S--) {
        numbers.pop();
    }

    if (numbers.empty()) {
        cout << '0' << endl;
        return 0;
    }

    int result = searchForX( numbers, X);
    if (result == X)
        cout << "true" << endl;
    else
        cout << result << endl;

    return 0;
}
