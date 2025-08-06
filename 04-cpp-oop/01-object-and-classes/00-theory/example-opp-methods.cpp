//
// Created by tonytech on 05.08.2025.
//
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class Person {
    class Body {
    public:
        double heightMeters;
        double weightKgs;

        Body(const double heightMeters, const double weightKgs) : heightMeters(heightMeters), weightKgs(weightKgs) {
            this->heightMeters = heightMeters;
            this->weightKgs = weightKgs;
        }

        [[nodiscard]] auto getInfo() const -> string {
            ostringstream info;
            info << "height: " << this->heightMeters << ", weight: " << this->weightKgs;

            return info.str();
        }
    };

public:
    string name;
    int age{};
    Body body;


    explicit Person(const string &name, const int &age, const double heightMeters, const double weightKgs) :
        name(name), age(age), body(heightMeters, weightKgs) {
        this->name = name;
        this->age = age;
        this->body = Body(heightMeters, weightKgs);
    }

    [[nodiscard]] auto getInfo() const -> string {
        ostringstream info;
        info << "name: " << this->name << ", age: " << this->age << ", " << this->body.getInfo();

        return info.str();
    }

    auto printInfo() const -> void {
        cout << "name: " << this->name << ", age: " << this->age << ", height: " << this->body.heightMeters
             << ", weight: " << this->body.weightKgs << endl;
    }

    auto makeOlder(const int year) -> void { this->age += year; }
};

auto printPerson(const Person &person) -> void {
    cout << "name: " << person.name << ", age: " << person.age << ", height(meter): " << person.body.heightMeters
         << ", weight(kg): " << person.body.weightKgs << endl;
}


int main() {
    printPerson(Person("Kojcho", 42, 1.83, 74.3));

    Person p1("Checho", 13, 1.43, 34);
    p1.printInfo();

    Person *personPtr = &p1;

    personPtr->makeOlder(2);
    personPtr->printInfo();

    personPtr->makeOlder(3);
    cout << personPtr->getInfo() << endl;
    cout << personPtr->body.getInfo() << endl;

    return 0;
}
