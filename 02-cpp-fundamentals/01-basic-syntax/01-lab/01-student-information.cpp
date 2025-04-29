#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string studentName;
    int studentAge;
    double studentGrade;

    getline(cin, studentName);
    cin >> studentAge >> studentGrade;

    cout << setprecision(2) << fixed;
    cout << "Name: " << studentName << ", Age: " << studentAge << ", Grade: " << studentGrade << endl;

    return 0;
}
