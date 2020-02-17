//
//  string2.cpp
//  string2
//
//  Created by stone on 2020/2/16.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "string2.hpp"
#include <cstring>

using std::cout;

int String::numStrings = 0;

int String::howMany() {
    return String::numStrings;
}

String::String() {
    len = 4;
    str = new char[1];
    str[0] = '\0';
    numStrings++;
}

String::String(const char* s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    numStrings++;
}

//复制构造函数 to initialize a new obj which will be same as s
String::String(const String & s) {
    numStrings++;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
}

String::~String() {
    --numStrings;
    delete[] str;
}

//重载赋值运算符 与复制构造函数相搭配使用 深度复制
String & String::operator=(const String & s) {
    if(this == &s) {
        return *this;
    }
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    return *this;
}

String & String::operator=(const char* s) {
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char & String::operator[] (int i) {
    return str[i];
}

const char & String::operator[](int i) const {
    return str[i];
}

bool operator<(const String & s1, const String & s2) {
    if(std::strcmp(s1.str, s2.str) < 0) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const String & s1, const String & s2) {
    return s2 < s1;
}

bool operator==(const String & s1, const String & s2) {
    return (std::strcmp(s1.str, s2.str) == 0);
}

std::istream & operator>>(std::istream & is, String & s) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if(is)
        s = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

std::ostream & operator<<(std::ostream & os, const String & s) {
    os << s.str;
    return os;
}


