#include <iostream>

using namespace std;

int main() {
    int the_number;
    cin >> the_number;

    double bonus = 0;

    if (the_number <= 100) {
        bonus = bonus + 5;
    } else if (the_number <= 1000) {
        bonus = the_number * 0.2;
    } else {
        bonus = the_number * 0.1;
    }

    if (the_number % 2 == 0) {
        bonus = bonus + 1;
    }

    if (the_number % 10 == 5) {
        bonus = bonus + 2;
    }

    cout << bonus << endl;
    cout << the_number + bonus << endl;

    return 0;
}
