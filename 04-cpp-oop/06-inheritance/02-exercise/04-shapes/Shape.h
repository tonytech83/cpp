//
// Created by tonytech on 11.09.2025.
//

#ifndef CPP_SHAPE_H
#define CPP_SHAPE_H

#include <sstream>
#include "Vector2D.h"

class Shape {
protected:
    Vector2D center;
    double area;

public:
    Shape() : center(0, 0), area(0) {}

    explicit Shape(const Vector2D &center) : center(center), area(0) {}

    [[nodiscard]] auto getCenter() const -> Vector2D { return center; }

    [[nodiscard]] auto getArea() const -> double { return this->area; }
};

#endif // CPP_SHAPE_H
