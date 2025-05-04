//
// Created by tonytech on 5/4/25.
//

#include <iostream>
using namespace std;

void printSign(int number);

int main() {
    int n;
    cin >> n;

    printSign(n);

    return 0;
}

void printSign(const int number) {
    cout << "The number " << number << " is ";

    if (number < 0) {
        cout << "negative." << endl;
    } else if (number == 0) {
        cout << "zero." << endl;
    } else {
        cout << "positive." << endl;
    }
}
