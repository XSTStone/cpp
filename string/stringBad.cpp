//
//  stringBad.cpp
//  string
//
//  Created by stone on 2020/2/15.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "stringBad.hpp"
#include <cstring>

using std::cout;

int StringBad::numStrings = 0;

StringBad::StringBad(const char* s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    numStrings++;
    cout << numStrings << ": \"" << str << "\" object created.\n";
}

StringBad::StringBad(const StringBad & s) {
    numStrings++;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    cout << numStrings << ": \"" << str << "\" object created.\n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    numStrings++;
    cout << numStrings << ": \"" << str << "\" object created.\n";
}

StringBad::~StringBad() {
    cout << "\"" << str << "\" object deleted, ";
    --numStrings;
    cout << numStrings << " left.\n";
    delete[] str;
}

StringBad & StringBad::operator=(const StringBad &s) {
    if(this == &s) {
        return *this;
    }
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const StringBad & s) {
    os << s.str;
    return os;
}
