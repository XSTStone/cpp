//
//  vector.hpp
//  vector
//
//  Created by stone on 2020/2/15.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp

#include <iostream>
namespace VECTOR {
class Vector {
public:
    enum Mode {RECT, POL};
private:
    double x;
    double y;
    double mag;
    double ang;
    Mode mode;
    void setMag();
    void setAng();
    void setX();
    void setY();
public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    void reset(double n1, double n2, Mode form = RECT);
    ~Vector();
    double xVal() const {return x;}
    double yVal() const {return y;}
    double magVal() const {return mag;}
    double angVal() const {return ang;}
    void modePolar();
    void modeRect();
    Vector operator+(const Vector & b) const;
    Vector operator-(const Vector & b) const;
    Vector operator-() const;
    Vector operator*(double n) const;
    friend Vector operator*(double n, const Vector & a);
    friend std::ostream & operator<<(std::ostream & os, const Vector & v);
};
}


#endif /* vector_hpp */
