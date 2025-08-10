//
// Created by tonytech on 10.8.2025.
//
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

class Point {
    double x;
    double y;

public:
    explicit Point(const double x = 0, const double y = 0) : x(x), y(y) {}

    [[nodiscard]] auto euclideanDistance(const Point &other) const -> double {
        return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
    }
};

auto main() -> int {
    double x = 0, y = 0;

    cin >> x >> y;
    const auto p1 = Point(x, y);

    cin >> x >> y;
    const auto p2 = Point(x, y);

    const double distance = p1.euclideanDistance(p2);

    cout << fixed << setprecision(3) << distance << endl;

    return 0;
}
