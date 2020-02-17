//
//  stock_2.hpp
//  Stock_2.0
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef stock_2_hpp
#define stock_2_hpp
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
    Stock (const std::string & co, long n, double pr);
    ~Stock();
    void buy (long num, double price);
    void sell (long num, double price);
    void update (double price);
    void show() const;
    const Stock & topVal (const Stock & s) const;
};


#endif /* stock_2_hpp */
