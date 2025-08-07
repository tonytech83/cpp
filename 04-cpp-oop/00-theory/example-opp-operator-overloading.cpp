//
// Created by tonytech on 06.08.2025.
//
#include <iostream>
using namespace std;

// Syntax:
//  type operator sing (parameters) { /*... body ...*/ }
//

class Vector2D {
public:
    double x, y;

    Vector2D(const double x, const double y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D &other) const { return {this->x + other.x, this->y + other.y}; }

    Vector2D operator+(const double &a) const { return {this->x + a, this->y + a}; }

    Vector2D operator*(const Vector2D &other) const { return {this->x * other.x, this->y * other.y}; }

    Vector2D operator*(const double &a) const { return {this->x * a, this->y * a}; }
};


auto main() -> int {
    const Vector2D a(1, 1);
    const Vector2D b(2, -1);

    const Vector2D c = a + b;
    cout << c.x << ", " << c.y << endl;

    const Vector2D d = c * b;
    cout << d.x << ", " << d.y << endl;

    const Vector2D e = a * 5;
    cout << e.x << ", " << e.y << endl;

    return 0;
}
