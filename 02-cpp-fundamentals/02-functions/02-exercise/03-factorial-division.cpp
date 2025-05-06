//
// Created by tonytech on 5/6/25.
//
#include <iostream>
using namespace std;

long long factorial(int n);

void printFactorialDivision(double result);

int main() {
    int a, b;
    cin >> a >> b;

    const long long f1 = factorial(a);
    const long long f2 = factorial(b);

    const double result = static_cast<double>(f1) / f2;
    printFactorialDivision(result);
    cout << endl;

    return 0;
}

long long factorial(const int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

void printFactorialDivision(const double result) {
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << result;
}
