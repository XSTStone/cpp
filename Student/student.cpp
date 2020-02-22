//
//  student.cpp
//  Student
//
//  Created by stone on 2020/2/22.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "student.hpp"


std::ostream & Student::arrOut(std::ostream & os) const {
    int i;
    int limit = scores.size();
    if(limit > 0) {
        for (i = 0; i < limit; ++i) {
            os << scores[i] << " ";
            if(i % 5 == 4) {
                os << std::endl;
            }
        }
        if(i % 5 != 0) {
            os << std::endl;
        }
    } else {
        os << "Empty array ";
    }
    return os;
}

double Student::Average() const {
    if(scores.size() == 0) {
        printf("Empty array.\n");
        return 0;
    } else {
        return (scores.sum() / scores.size());
    }
}

const std::string & Student::Name() const {
    return name;
}

double & Student::operator[](int i) {
    return scores[i];
}

double Student::operator[](int i) const {
    printf("Using second fun.\n");
    return scores[i];
}

std::istream & operator>>(std::istream & is, Student & stu) {
    is >> stu.name;
    return is;
}

std::istream & getline(std::istream & is, Student & stu) {
    getline(is, stu.name);
    return is;
}

std::ostream & operator<<(std::ostream & os, Student & stu) {
    os << "Scores for " << stu.name << ":\n";
    stu.arrOut(os);
    return os;
}
