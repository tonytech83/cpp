//
// Created by tonytech on 18.08.2025.
//
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// polymorphism
// poly morphism
// many forms

// Categories:
//
// 1. Compiletime polymorphism
// - Function overloading
// - Operator overloading
//
// 2. Runtime polimorphism
// - Virtual functions

// Function overloading
auto test() -> void {}
auto test(int a) -> void {}
auto test(int a, double b) -> void {}

// Operator overloading
auto operator<<(ostream &out, const vector<int> &v) -> ostream & {
    for (int i(0); i < v.size(); i++) {
        if (i)
            out << ", ";
        out << v.at(i);
    }
    return out;
}

auto operator+=(vector<int> &lhs, const vector<int> &rhl) -> vector<int> & {
    for (int i: rhl)
        lhs.push_back(i);

    return lhs;
}

// Virtual functions
class Box {
protected:
    float width{1.0f};
    float height{2.0f};

public:
    virtual auto toString() const -> void {
        cout << "Box\n" << "width: " << this->width << "\n" << "height: " << this->height << endl;
    }
};

class SuperBox : public Box {
    float value{3.0f};

public:
    auto toString() const -> void override {
        cout << "SuperBox" << endl
             << "width: " << this->width << endl
             << "height: " << this->height << endl
             << "value: " << this->value << endl;
    }
};

auto main() -> int {
    // Function overloading
    vector<int> items;
    items.push_back(1);
    items.push_back(2);
    items.push_back(3);
    items.push_back(4);
    cout << items << endl;

    // Operator overloading
    vector<int> newItems;
    newItems.push_back(5);
    newItems.push_back(6);
    newItems.push_back(7);
    newItems.push_back(8);

    items += newItems;
    cout << items << endl;

    // Virtual functions

    // We should use pointers, because when we add SuberBox to our vector of Boxes , it will be implicit cast to Box
    // vector<Box> boxes; -> [Box, Box, Box] - the vector contains objects of type Box
    // vector<Box*> boxes; -> [Box*, Box*, Box] - the vector contains pointes !!!
    vector<Box*> boxes;
    Box box;
    SuperBox sBox;
    boxes.emplace_back(&box);
    boxes.emplace_back(&sBox);

    for (const auto &it: boxes)
        it->toString();

    return 0;
}
