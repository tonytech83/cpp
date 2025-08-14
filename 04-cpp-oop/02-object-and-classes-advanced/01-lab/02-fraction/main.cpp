//
// Created by tonytech on 14.08.2025.
//
#include <iostream>
#include <set>

#include "Fraction.h"

using namespace std;

auto main() -> int {
    set fractions{Fraction(1, 3), Fraction(2, 10), Fraction(2, 6)};

    Fraction f13{1, 3}, f24{2, 4}, f25{2, 5};

    Fraction f43 = f13++;
    Fraction f43b = ++f13;

    Fraction myF1;

    cin >> myF1 << endl;
    cout << "You entered: " << myF1 << " value." << endl;
    myF1.reduce();
    cout << "You entered (reduced): " << myF1 << " value." << endl;

    auto a = Fraction(1, 2);
    auto b = Fraction(2, 4);

    cout << b.getFraction() << endl;
    b.reduce();
    cout << b.getFraction() << endl;


    return 0;
}
