//
// Created by tonytech on 07.08.2025.
//
#include <iostream>
#include <sstream>
using namespace std;

// If define method or operator as const, this mean it can modify the instance it is called on

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

auto main() -> int {
    // if Person is declared as const, we can call only constant methods on it!
    const Person p("Koko", 2);
    cout << p.getInfo() << endl;

    return 0;
}
