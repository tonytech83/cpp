//
// Created by tonytech on 10.8.2025.
//
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Student {
    string name;
    string surname;
    double totalAverage = 0;

public:
    auto read(istream &is) -> void { is >> name >> surname >> totalAverage; }

    [[nodiscard]] auto getName() const -> string { return name; }

    [[nodiscard]] auto getSurname() const -> string { return surname; }

    [[nodiscard]] auto getTotalAverage() const -> double { return totalAverage; }

    [[nodiscard]] auto print() const -> string {
        ostringstream oss;
        oss << name << " " << surname << " " << totalAverage;

        return oss.str();
    }

    [[nodiscard]] auto setAverage() const -> double { return this->totalAverage; }
};

auto totalAverageOfAllStudents(const vector<Student> &students) -> double {
    double total = 0;

    for (auto &student: students) {
        total += student.setAverage();
    }

    return total / static_cast<int>(students.size());
}

auto main() -> int {
    vector<Student> students;

    int count;
    cin >> count;
    if (count <= 0) {
        cout << "Invalid input" << endl;
        return 0;
    }

    students.reserve(count);

    while (count--) {
        auto student = Student();
        student.read(cin);
        students.emplace_back(student);
    }

    for (auto &student: students)
        cout << student.print() << endl;

    cout << totalAverageOfAllStudents(students) << endl;

    return 0;
}
