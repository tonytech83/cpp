//
// Created by tonytech on 5/4/25.
//

#include <iostream>
using namespace std;

void printSign(const int number) {
    if (number < 0) {
        cout << "The number " << number << " is negative." << endl;
    } else if (number == 0) {
        cout << "The number " << number << " is zero." << endl;
    } else {
        cout << "The number " << number << " is positive." << endl;
    }
}

int main() {
    int n;
    cin >> n;

    printSign(n);

    return 0;
}
