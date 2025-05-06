//
// Created by tonytech on 5/6/25.
//

#include <iostream>
#include <string>
using namespace std;

string nameOfNumber(int number);

string nameOfNumberTeens(int number);

string nameOfNumberTenth(int number);

int main() {
    int number; // number is ib range [0, 9999]
    cin >> number;

    if (number == 0) {
        cout << "zero" << endl;
        return 0;
    }

    // number == 9574
    const int n1 = number % 10; // 9574 % 10 = 4
    const int n10 = (number / 10) % 10; // 9574 / 10 = 957 % 10 = 7
    const int n100 = (number / 100) % 10; // 9574 / 100 = 95 % 10 = 5
    const int n1000 = number / 1000; // 9574 / 1000  =  9

    if (n1000)
        cout << nameOfNumber(n1000) << " thousand ";
    if (n100)
        cout << nameOfNumber(n100) << " hundred ";
    if (n10 >= 2)
        cout << nameOfNumberTenth(n10) << ' ';
    if (n10 == 1)
        cout << nameOfNumberTeens(n1);
    else if (n1)
        cout << nameOfNumber(n1);
    cout << endl;

    return 0;
}

string nameOfNumber(const int number) {
    switch (number) {
        case 0: return "zero";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
    }

    return "";
}

string nameOfNumberTeens(const int number) {
    switch (number) {
        case 0: return "ten";
        case 1: return "eleven";
        case 2: return "twelve";
        case 3: return "thirteen";
        case 4: return "fourteen";
        case 5: return "fifteen";
        case 6: return "sixteen";
        case 7: return "seventeen";
        case 8: return "eighteen";
        case 9: return "nineteen";
    }

    return "";
}

string nameOfNumberTenth(const int number) {
    switch (number) {
        case 2: return "twenty";
        case 3: return "thirty";
        case 4: return "forty";
        case 5: return "fifty";
        case 6: return "six";
        case 7: return "seventy";
        case 8: return "eighty";
        case 9: return "ninety";
    }

    return "";
}
