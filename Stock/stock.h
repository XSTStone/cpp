//
//  stock.h
//  C++
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef stock_h
#define stock_h

#include <string>

class Stock {
private:
    std::string company;
    long shares;
    double shareVal;
    double totalVal;
    void setTotal () {
        totalVal = shares * shareVal;
    }
public:
    Stock (const std::string & co, long n = 0, double pr = 0.0);
    Stock ();
    void acquire (const std::string & co, long n, double pr);
    void buy (long num, double price);
    void sell (long num, double price);
    void update (double price);
    void show();
    ~Stock();
};

#endif /* stock_h */
