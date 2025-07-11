//
// Created by tonytech on 28.6.2025.
//
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;


auto main() -> int {
    int namesCount;
    cin >> namesCount;
    cin.ignore();

    map<string, vector<double>> students;

    while (namesCount--) {
        string name;
        double grade;
        cin >> name >> grade;

        // students[name] returns `vector<double> &` - reference
        students[name].push_back(grade);
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    for (auto [name, grades]: students) {
        cout << name << " -> ";
        const double average = accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
        for (const double grade: grades)
            cout << grade << ' ';
        cout << "(avg: " << average << ')' << endl;
    }

    return 0;
}
