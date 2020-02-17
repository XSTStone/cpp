//
//  stringBad.hpp
//  string
//
//  Created by stone on 2020/2/15.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef stringBad_hpp
#define stringBad_hpp
#include <iostream>

class StringBad {
private:
    char* str;
    int len;
    static int numStrings;
public:
    StringBad();
    StringBad(const char* s);
    StringBad(const StringBad & s);
    ~StringBad();
    StringBad & operator=(const StringBad & s);
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

#endif /* stringBad_hpp */
