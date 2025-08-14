//
// Created by tonytech on 14.08.2025.
//
#include <iostream>
#include <set>

#include "Fraction.h"

using namespace std;

auto main() -> int {
    set fractions{Fraction(1, 3), Fraction(2, 10), Fraction(2, 6)};

    Fraction f13{1, 3};
    const Fraction f25{2, 5};
    const Fraction f24{2, 4};

    const Fraction f43 = f13++;
    const Fraction f43b = ++f13;
    cout << f43 << endl;
    cout << f43b << endl;

    Fraction myF1;

    cin >> myF1;
    cout << "You entered: " << myF1 << " value." << endl;
    myF1.reduce();
    cout << "You entered (reduced): " << myF1 << " value." << endl;

    Fraction fR = myF1 + f13;
    cout << fR << endl;

    fR = myF1 - Fraction(1,12);
    cout << fR << endl;

    Fraction first, second;
    cin >> first >> second;

    cout << (first == second) << endl;

    (((cout << f13) << ' ' << f24) << ' ' << f25) <<endl;
    cout << myF1 << endl;

    return 0;
}
