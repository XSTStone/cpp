//
//  student_Implicit.cpp
//  Student
//
//  Created by stone on 2020/2/22.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "student_Implicit.hpp"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

ostream & Student::arrOut(ostream & os) const {
    int i;
    int limit = ArrayDb::size();
    if(limit > 0) {
        for (i = 0;i < limit;++i) {
            os << ArrayDb::operator[](i) << " ";
            if(i % 5 == 4)
                os << endl;
        }
        if(i % 5 != 0)
            os << endl;
    } else {
        os << " Empty Array ";
    }
    return os;
}

double Student::Average() const {
    if(ArrayDb::size() > 0) {
        return (ArrayDb::sum() / ArrayDb::size());
    } else {
        return 0;
    }
}

const string & Student::Name() const {
    return (const string &) *this;
}

double & Student::operator[](int i) {
    return ArrayDb::operator[](i);
}

double Student::operator[](int i) const {
    return ArrayDb::operator[](i);
}

istream & operator>>(istream & is, Student & stu) {
    is >> (string &) stu;
    return is;
}

istream & getline(istream & is, Student & stu) {
    getline(is, (string &) stu);
    return is;
}

ostream & operator<<(ostream & os, Student & stu) {
    os << "Scores for " << (const string &) stu << ".\n";
    stu.arrOut(os);
    return os;
}
