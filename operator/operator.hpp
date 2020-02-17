//
//  operator.hpp
//  operator
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef operator_hpp
#define operator_hpp
#include <iostream>

class Time {
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int hour, int minute = 0);
    void addMinute(int minute);
    void addHour(int hour);
    void reset(int hour = 0, int minute = 0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double times) const;
    friend Time operator*(double times, const Time & t) {
        std::cout << "OKOK" << std::endl;
        return t * times;
    }
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};


#endif /* operator_hpp */
