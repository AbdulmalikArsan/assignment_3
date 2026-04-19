#include <iostream>
#include <algorithm>
#include <cmath>

#include "include/triangles.hpp"

Triangle::Triangle() : _t1(), _t2(), _t3() { }

Triangle::Triangle(Point2D t1, Point2D t2, Point2D t3) 
    : _t1(t1), _t2(t2), _t3(t3) { }

void Triangle::SetT1(Point2D t1) { _t1 = t1; }
void Triangle::SetT2(Point2D t2) { _t2 = t2; }
void Triangle::SetT3(Point2D t3) { _t3 = t3; }

std::string Triangle::GetType() const {
    float a = _t1.Distance(_t2);
    float b = _t2.Distance(_t3);
    float c = _t3.Distance(_t1);
    
    // Sort sides
    float sides[3] = {a, b, c};
    std::sort(sides, sides + 3);
    
    // Check for equilateral (sama sisi)
    if (std::abs(sides[0] - sides[1]) < 1e-5 && 
        std::abs(sides[1] - sides[2]) < 1e-5) {
        return "sama sisi";
    }
    
    // Check for right-angled (siku-siku) using Pythagorean theorem
    float epsilon = 1e-5;
    if (std::abs(sides[0]*sides[0] + sides[1]*sides[1] - sides[2]*sides[2]) < epsilon) {
        return "siku-siku";
    }
    
    // Check for isosceles (sama kaki) - two sides equal
    if (std::abs(a - b) < 1e-5 || std::abs(b - c) < 1e-5 || std::abs(a - c) < 1e-5) {
        return "sama kaki";
    }
    
    // Otherwise scalene (sembarang)
    return "sembarang";
}