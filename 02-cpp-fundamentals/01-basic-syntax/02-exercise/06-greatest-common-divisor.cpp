//
// Created by tonytech on 5/1/25.
//

#include <iostream>
#include <utility>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (b > a)
        swap(a, b);

    // Euclidean algorithm
    while (b) {
        int t = b;
        b = a % t;
        a = t;
    }

    cout << a << endl;

    return 0;
}
