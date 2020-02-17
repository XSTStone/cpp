//
//  operator.cpp
//  operator
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "operator.hpp"
#include <iostream>

Time::Time() {
    hours = minutes = 0;
}

Time::Time(int hour, int minute) {
    hours = hour + minute / 60;
    minutes = minute % 60;
}

void Time::addMinute(int minute) {
    minutes += minute;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::addHour(int hour) {
    hours += hour;
}

void Time::reset(int hour, int minute) {
    hours = hour;
    minutes = minute;
}

Time Time::operator+(const Time & t) const {
    Time total;
    total.minutes = this->minutes + t.minutes;
    total.hours += total.minutes / 60;
    total.minutes %= 60;
    total.hours += this->hours + t.hours;
    return total;
}

Time Time::operator-(const Time &t) const {
    Time diff;
    int tot1, tot2;
    tot1 = this->minutes + this->hours * 60;
    tot2 = t.minutes + t.hours * 60;
    diff.hours = (tot1 - tot2) / 60;
    diff.minutes = (tot1 - tot2) % 60;
    return diff;
}

Time Time::operator*(double times) const {
    Time result;
    long totalMinutes = this->hours * 60 * times + this->minutes * times;
    result.hours = totalMinutes / 60;
    result.minutes = totalMinutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t) {
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}
