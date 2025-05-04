//
// Created by tonytech on 5/4/25.
//

#include <iostream>
using namespace std;

int getMinOfThree(int a, int b, int c);

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << getMinOfThree(a, b, c) << endl;

    return 0;
}

int getMinOfThree(const int a, const int b, const int c) {
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }

    return smallest;
}
