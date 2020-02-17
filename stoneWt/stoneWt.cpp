//
//  stoneWt.cpp
//  stoneWt
//
//  Created by stone on 2020/2/15.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "stoneWt.hpp"
#include <iostream>
using std::cout;

Stonewt::Stonewt() {
    stone = pounds = pdsLeft = 0;
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pdsLeft = lbs;
    pounds = stn * lbsPerStn + lbs;
}

Stonewt::Stonewt(double lbs) {
    pounds = lbs;
    stone = int(lbs) / lbsPerStn;
    pdsLeft = int(lbs) % lbsPerStn + lbs - int(lbs);
}

Stonewt::~Stonewt() {}

void Stonewt::showStn() const {
    cout << stone << " stone, " << pdsLeft << " pounds.\n";
}

void Stonewt::showLbs() const {
    cout << pounds << " pounds.\n";
}

Stonewt::operator double() const {
    return pounds;
}

Stonewt::operator int() const {
    return int(pounds + 0.5);
}

Stonewt operator+(const Stonewt & stn1, const Stonewt & stn2) {
    double pds = stn1.pounds + stn2.pounds;
    Stonewt sum(pds);
    return sum;
}

