//
// Created by tonytech on 4/26/25.
//

#include <iostream>

using namespace std;

int main() {
    string studentName;
    int studentAge;
    double studentGrade;

    cin >> studentName >> studentAge >> studentGrade;

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Name: " << studentName << ", Age: "<< studentAge<< ", Grade: " << studentGrade << endl;

    return 0;
}
