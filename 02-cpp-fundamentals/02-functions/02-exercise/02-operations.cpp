//
// Created by tonytech on 5/6/25.
//

#include <iostream>
using namespace std;

int addition(int a, int b);

int subtraction(int a, int b);

int multiplication(int a, int b);

int division(int a, int b);

int calculate(char operation, int a, int b);

int main() {
    int a, b;
    cin >> a >> b;

    char op;
    cin >> op;

    cout << calculate(op, a, b) << endl;

    return 0;
}

int addition(const int a, const int b) {
    return a + b;
}

int subtraction(const int a, const int b) {
    return a - b;
}

int multiplication(const int a, const int b) {
    return a * b;
}

int division(const int a, const int b) {
    return a / b;
}

int calculate(const char operation, const int a, const int b) {
    switch (operation) {
        case '+': return addition(a, b);
        case '-': return subtraction(a, b);
        case '*': return multiplication(a, b);
        case '/': return division(a, b);
        default: return 0;
    }
}
