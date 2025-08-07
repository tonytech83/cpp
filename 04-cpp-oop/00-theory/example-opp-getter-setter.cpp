//
// Encapsulation
//

#include <iostream>
#include <sstream>
using namespace std;

constexpr double PI = 3.14;

class Circle {
    double radius;
    double area;

public:
    explicit Circle(const double &radius) : radius(radius), area(PI * radius * radius) {}

    auto setRadius(const double &radius) -> void {
        this->radius = radius;
        this->area = PI * radius * radius;
    }

private:
    [[nodiscard]] auto getArea() const -> double { return this->area; }

public:
    [[nodiscard]] auto getInfo() const -> string {
        ostringstream oss;
        oss << "Circle: " << endl;
        oss << "    radius = " << this->radius << ", area: " << this->getArea();

        return oss.str();
    }
};

int main() {
    Circle c(10);

    cout << c.getInfo() << endl;

    c.setRadius(20);

    cout << c.getInfo() << endl;

    return 0;
}
