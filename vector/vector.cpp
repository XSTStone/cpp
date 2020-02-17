//
//  vector.cpp
//  vector
//
//  Created by stone on 2020/2/15.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "vector.hpp"
#include <cmath>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
const double radToDeg = 45.0 / atan(1.0);
void Vector::setMag() {
    mag = sqrt(x * x + y * y);
}

void Vector::setAng() {
    if(x == 0 && y == 0) {
        ang = 0.0;
    } else {
        ang = atan2(y, x);
    }
}

void Vector::setX() {
    x = mag * cos(ang);
}

void Vector::setY() {
    y = mag * sin(ang);
}

Vector::Vector() {
    x = y = mag = ang = 0.0;
    mode = RECT;
}

Vector::Vector(double n1, double n2, Mode form) {
    mode = form;
    if(form == RECT) {
        x = n1;
        y = n2;
        setAng();
        setMag();
    } else if(form == POL) {
        mag = n1;
        ang = n2 / radToDeg;
        setX();
        setY();
    } else {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0. Vector mode set to RECT.\n";
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
}

void Vector::reset(double n1, double n2, Mode form) {
    mode = form;
    if(form == RECT) {
        x = n1;
        y = n2;
        setAng();
        setMag();
    } else if(form == POL) {
        mag = n1;
        ang = n2 / radToDeg;
        setY();
        setX();
    } else {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0. Vector mode set to RECT.\n";
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
}

Vector::~Vector() {}

void Vector::modePolar() {
    mode = POL;
}

void Vector::modeRect() {
    mode = RECT;
}

Vector Vector::operator+(const Vector &b) const {
    return Vector(x + b.x, y + b.y);
}

Vector Vector::operator-(const Vector &b) const {
    return Vector(x - b.x, y - b.y);
}

Vector Vector::operator-() const {
    return Vector(-x, -y);
}

Vector Vector::operator*(double n) const {
    return Vector(n * x, n * y);
}

Vector operator*(double n, const Vector & a) {
    return (a * n);
}

std::ostream & operator<<(std::ostream & os, const Vector & v) {
    if(v.mode == Vector::RECT) {
        os << "(x,y) = (" << v.x << ", " << v.y << ")\n";
    } else if(v.mode == Vector::POL) {
        os << "(m,a) = (" << v.mag << ", " << v.ang * radToDeg << ")\n";
    } else {
        os << "Vector object mode is invalid";
    }
    return os;
}
    
}

