//
//  stoneWt.hpp
//  stoneWt
//
//  Created by stone on 2020/2/15.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef stoneWt_hpp
#define stoneWt_hpp

class Stonewt {
private:
    enum {lbsPerStn = 14};
    int stone;
    double pdsLeft;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void showLbs() const;
    void showStn() const;
    operator double() const;
    operator int() const;
    friend Stonewt operator+(const Stonewt & stn1, const Stonewt & stn2);
};

#endif /* stoneWt_hpp */
