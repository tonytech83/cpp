//
// Created by tonytech on 5/4/25.
//

#include <iostream>
using namespace std;

void printTriangle(int n);

void printLine1toN(int N);

int main() {
    int n;
    cin >> n;

    printTriangle(n);

    return 0;
}

void printLine1toN(const int N) {
    for (int j = 1; j <= N; j++)
        cout << j << ' ';

    cout << endl;
}


void printTriangle(const int n) {
    for (int curr = 1; curr <= n; curr++)
        printLine1toN(curr);

    for (int curr = n - 1; curr > 0; curr--)
        printLine1toN(curr);
}
