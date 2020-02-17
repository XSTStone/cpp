//
//  stock_3.hpp
//  Stock_3.0
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef stock_3_hpp
#define stock_3_hpp
#include <string>

class Stock {
private:
    std::string company;
    long shares;
    double shareVal;
    double totalVal;
    void setTotal() {
        totalVal = shareVal * shares;
    }
public:
    Stock();
    Stock(const std::string & co, long n = 0, double pr = 0.0);
    ~Stock();
    void buy(long n, double price);
    void sell(long n, double price);
    void update(double price);
    void show() const;
    const Stock & topVal(const Stock & s) const;
};
#endif /* stock_3_hpp */
