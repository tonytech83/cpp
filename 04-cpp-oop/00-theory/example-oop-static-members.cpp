//
// Created by tonytech on 07.08.2025.
//

#include <iostream>
using namespace std;

class Person {
    static int personCount;
    static int totalPersonAge;

public:
    string name;
    int age;

    explicit Person(const string &name = "", const int &age = 0) {
        this->name = name;
        this->age = age;

        Person::totalPersonAge += this->age;
        Person::personCount++;
    }

    ~Person() {
        Person::totalPersonAge -= this->age;
        Person::personCount--;
    }

    static auto getAveragePersonAge() -> int { return Person::totalPersonAge / Person::personCount; }

    static auto getCount() -> int { return Person::personCount; }
};

// Static member definitions
int Person::personCount = 0;
int Person::totalPersonAge = 0;

auto main() -> int {
    Person person1("p1", 24);
    Person person2("p2", 44);

    cout << "Persons count: " << Person::getCount() << endl;
    cout << Person::getAveragePersonAge() << endl;

    {
        Person person3("p3", 54);
        cout << "Persons count: " << Person::getCount() << endl;
        cout << Person::getAveragePersonAge() << endl;
    }

    cout << "Persons count: " << Person::getCount() << endl;
    cout << Person::getAveragePersonAge() << endl;

    return 0;
}
