//
// Created by tonytech on 11.08.2025.
//
#include <iostream>
using namespace std;

// Inheritance
class Base {
public:
    int x;

protected:
    int y;

private:
    int z;
};

class PublicDerived : public Base {
    // x is public
    // y is protected
    // x is not accessible form PublicDerived
};

class ProtectedDerived : protected Base {
    // x is protected
    // y is protected
    // x is not accessible form ProtectedDerived
};

class PrivateDerived : private Base {
    // x is private
    // y is private
    // x is not accessible form PrivateDerived
};

/////////

class Box {
protected:
    float width{1.0f};
    float height{2.0f};

public:
    auto toString() const -> void { printf("Box\nwidth: %f\nheight: %f\n", this->width, this->height); }
};

class SuperBox : public Box {
private:
    float value{3.0f};

public:
    auto toString() const -> void {
        printf("SuperBox\nwidth: %f\nheight: %f\nvalue: %f\n", this->width, this->height, this->value);
    }
};


auto main() -> int {
    const Box b;
    const SuperBox sb;

    b.toString();
    sb.toString();

    // Access the parent class toString method
    sb.Box::toString();

    return 0;
}
