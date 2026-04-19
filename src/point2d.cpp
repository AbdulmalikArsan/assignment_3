#include <iostream>
#include <cmath>

#include "include/point2d.hpp"

Point2D::Point2D() : _x(0), _y(0) { }

Point2D::Point2D(float x, float y) : _x(x), _y(y) { }

float Point2D::Distance(const Point2D& other) const {
    float dx = _x - other._x;
    float dy = _y - other._y;
    return std::sqrt(dx*dx + dy*dy);
}