//
// Created by tonytech on 18.08.2025.
//
#include <iostream>
using namespace std;

// Abstract class
class Dog {
public:
    string breed;
    virtual auto bark() -> void { cout << "Bark" << endl; }

    // pure virtual function
    virtual void sleep() = 0;

    virtual ~Dog() = default;
};

class Husky : public Dog {
public:
    void sleep() override { cout << "Sleep" << endl; }
};

// Interface class - class contains only virtual functions
class IDog {
public:
    string name;

    virtual void bark() = 0;
    virtual void sleep() = 0;
};

class Huskyy : public IDog {
    void bark() override { cout << "Bark" << endl; }
    void sleep() override { cout << "Sleep" << endl; }
};

auto main() -> int {
    // Can't initialize object from class Dog, because the class is Abstract
    Dog d;
    Husky h;

    // Can't initialize object from class IDog, because the class is Interface
    IDog i;
    Huskyy hy;

    return 0;
}
