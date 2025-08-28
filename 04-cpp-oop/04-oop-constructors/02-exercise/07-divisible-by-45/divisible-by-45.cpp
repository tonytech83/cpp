//
// Created by tonytech on 28.08.2025.
//
#include <iostream>
#include "BigInt.h"
using namespace std;

constexpr int divider = 45;

// number should be divisible to 5 and 9
// to be divisible to 5 => number should end with '0' or '5'
// to be divisible to 9 => sum(all digits) % 9 == 0

auto isDivisibleBy5(const BigInt &big_int) -> bool {
    const string numStr = big_int.getDigits();
    return numStr.back() == '5' || numStr.back() == '0';
}

auto isDivisibleBy9(const BigInt &big_int) -> bool {
    int allDigitsSum = 0;
    for (const char ch: big_int.getDigits())
        allDigitsSum += ch - '0';

    return allDigitsSum % 9 == 0;
}

auto isDivisibleBy45(const BigInt &big_int) -> bool { return isDivisibleBy5(big_int) && isDivisibleBy9(big_int); }

auto main() -> int {
    string start, end;
    getline(cin, start);
    getline(cin, end);

    BigInt s(start);
    const BigInt e(end);

    while (s < e) {
        if (isDivisibleBy45(s))
            cout << s << endl;
        s += 1;
    }
}
