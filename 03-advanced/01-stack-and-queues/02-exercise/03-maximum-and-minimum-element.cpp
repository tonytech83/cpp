//
// Created by tonytech on 6/21/25.
//
#include <iostream>
#include <sstream>
#include <stack>
#include <climits>
using namespace std;

int findMinimum(stack<int> stck) {
    int minNumer = INT_MAX;
    while (!stck.empty()) {
        int currNumber = stck.top();
        stck.pop();

        if (currNumber < minNumer)
            minNumer = currNumber;
    }

    return minNumer;
}

int findMaximum(stack<int> stck) {
    int maxNumer = INT_MIN;
    while (!stck.empty()) {
        int currNumber = stck.top();
        stck.pop();

        if (currNumber > maxNumer)
            maxNumer = currNumber;
    }

    return maxNumer;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    stack<int> numbers;

    while (N--) {
        string command;
        getline(cin, command);

        switch (command[0]) {
            case '1': {
                istringstream iss(command);
                int c, number;
                iss >> c >> number;
                numbers.push(number);
                break;
            }
            case '2':
                if (!numbers.empty())
                    numbers.pop();
                break;
            case '3':
                if (!numbers.empty())
                    cout << findMaximum(numbers) << endl;
                break;
            case '4':
                if (!numbers.empty())
                    cout << findMinimum(numbers) << endl;
                break;
        }
    }

    while (numbers.size() > 1) {
        cout << numbers.top() << ", ";
        numbers.pop();
    }
    cout << numbers.top() << endl;

    return 0;
}
