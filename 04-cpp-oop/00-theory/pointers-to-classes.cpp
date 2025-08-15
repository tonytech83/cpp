//
// Created by tonytech on 07.08.2025.
//
#include <iostream>
#include <sstream>
using namespace std;

class Person {
    string name;
    int age;

public:
    explicit Person(const string &name, const int &age) {
        this->name = name;
        this->age = age;
    }

    [[nodiscard]] auto getInfo() const -> string {
        stringstream ss;
        ss << this->name << ", age: " << this->age;

        return ss.str();
    }
};

auto getPersonInfo(const Person &p) -> string { return p.getInfo(); }

auto main() -> int {

    const Person p("Koko", 2);
    cout << getPersonInfo(p) << endl;

    const Person *samPtr = new Person("Sam", 18);
    const auto frodo = Person("Frodo", 19);
    const Person *frodoPtr = &frodo;

    cout << getPersonInfo(*samPtr) << endl;
    cout << frodoPtr->getInfo() << endl;
    // dereferencing
    cout << (*samPtr).getInfo() << endl;

    delete samPtr;

    return 0;
}
