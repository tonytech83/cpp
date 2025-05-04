//
// Created by tonytech on 5/4/25.
//

#include <iostream>
using namespace std;

void printGradeInWord(double grade);

int main() {
    double grade;
    cin >> grade;

    printGradeInWord(grade);

    return 0;
}

void printGradeInWord(const double grade) {
    if (grade <= 2.99) {
        cout << "Fail" << endl;
    } else if (grade >= 3.00 && grade < 3.5) {
        cout << "Poor" << endl;
    } else if (grade >= 3.50 && grade < 4.5) {
        cout << "Good" << endl;
    } else if (grade >= 4.50 && grade < 5.5) {
        cout << "Very good" << endl;
    } else {
        cout << "Excellent" << endl;
    }
}