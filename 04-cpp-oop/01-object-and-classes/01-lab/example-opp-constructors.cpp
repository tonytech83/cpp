//
// Created by tonytech on 04.08.2025.
//

#include <iostream>
#include <vector>
using namespace std;


class Person {
    class Body {
    public:
        double heightMeters;
        double weightKgs;

        Body(const double heightMeters, const double weightKgs) : heightMeters(heightMeters), weightKgs(weightKgs) {}
    };

public:
    string name;
    int age{};

    explicit Person() = default;

    explicit Person(const string &name, const int &age) {
        this->name = name;
        this->age = age;
    }

    explicit Person(const string &personInfo) { // e.g. format: "022Tony" -> Tony, age 22
        this->name = personInfo.substr(3);
        this->age = 100 * (personInfo[0] - '0') + 10 * (personInfo[1] - '0') + (personInfo[2] - '0');
    }

    explicit Person(const string &json, bool isJson) { // e.g. format: "{name:'Phill', age:'34'}"
        // Find the position of name start and end
        const size_t nameStart = json.find("name:'") + 6;
        const size_t nameEnd = json.find('\'', nameStart);
        this->name = json.substr(nameStart, nameEnd - nameStart);

        // Find the position of age start and end
        const size_t ageStart = json.find("age:'") + 5;
        const size_t ageEnd = json.find('\'', ageStart);
        const string ageStr = json.substr(ageStart, ageEnd - ageStart);
        this->age = stoi(ageStr);
    }

    [[nodiscard]] auto getAge() const -> int { return this->age; }
};


int main() {
    const Person p1("John", 10);
    const Person p2("019Jane");
    const Person p3(string("{name:'Phill', age:'34'}"), true);

    vector<Person> persons;

    persons.reserve(10);
    for (int i = 0; i < 10; i++) {
        persons.emplace_back();
    }

    cout << p1.name << ", age " << p1.getAge() << endl;
    cout << p2.name << ", age " << p2.getAge() << endl;
    cout << p3.name << ", age " << p3.getAge() << endl;

    for (int idx = 0; idx < 10; idx++) {
        cout << idx << ' ' << persons[idx].name << ", age " << persons[idx].getAge() << endl;
    }

    return 0;
}
