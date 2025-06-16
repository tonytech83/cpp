//
// Created by tonytech on 16.06.2025.
//
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string buffer;
    getline(cin, buffer);
    istringstream iss(buffer);

    int result = 0;

    stack<int> numbers;
    stack<char> operators;

    int number;
    char op;
    iss >> number;
    numbers.push(number);

    while (iss >> op) {
        operators.push(op);
        iss >> number;
        numbers.push(number);
    }

    while (!operators.empty()) {
        if (operators.top() == '+')
            result += numbers.top();
        else
            result -= numbers.top();

        numbers.pop();
        operators.pop();
    }

    result += numbers.top();
    cout << result << endl;

    return 0;
}
