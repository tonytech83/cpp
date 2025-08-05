//
// Created by tonytech on 04.08.2025.
//
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    explicit Person(const string &name, const int age = -1) {
        this->name = name;
        this->age = age;
    }

    [[nodiscard]] auto getAge() const -> int { return this->age; }
};

int main() {
    auto p1 = Person("John");
    const Person p2("Tony", 22);

    const auto p3 = make_unique<Person>("Jane", 34);

    cout << "============ person from constructor ============" << endl;
    cout << p1.name << endl;
    cout << p1.getAge() << endl;


    cout << "============ change person attributes ============" << endl;
    p1.name = "Vans";
    p1.age = 20;

    cout << p1.name << endl;
    cout << p1.getAge() << endl;

    cout << "========================= p2 ========================" << endl;
    cout << p2.name << endl;
    cout << p2.getAge() << endl;

    p1.name = p2.name;
    p1.age = p2.age;

    cout << "========================= p1 ========================" << endl;
    cout << p1.name << endl;
    cout << p1.getAge() << endl;

    cout << "========================= p3 ========================" << endl;
    cout << p3->name << endl;
    cout << p3->getAge() << endl;

    return 0;
}
