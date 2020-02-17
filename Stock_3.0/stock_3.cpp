//
//  stock_3.cpp
//  Stock_3.0
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "stock_3.hpp"
#include <iostream>

Stock::Stock() {
    company = "no name";
    shareVal = 0.0;
    shares = 0;
    totalVal = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr) {
    company = co;
    
    if(n < 0) {
        std::cout << "Number of shares can't be negative." << company << " shares set to 0.\n";
        shares = 0;
    } else {
        shares = n;
    }
    shareVal = pr;
    setTotal();
}

Stock::~Stock() {
    std::cout << "Bye " << company << "!\n";
}

void Stock::buy(long n, double price) {
    if(n < 0) {
        std::cout << "Number of shares can't be negative." << " Transaction is absorted.\n";
    } else {
        shares += n;
        shareVal = price;
        setTotal();
    }
}

void Stock::sell(long n, double price) {
    if(n < 0) {
        std::cout << "Number of shares can't be negative." << " Transaction is absorted.\n";
    } else if(n > shares) {
        std::cout << "You can't sell more than you have!\n";
    } else {
        shares -= n;
        shareVal = price;
        setTotal();
    }
}

void Stock::update(double price) {
    shareVal = price;
    setTotal();
}

void Stock::show() const {
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    
    cout << "Company: " << company << "  Share: " << shares << '\n';
    cout << "   Share Price: $" << shareVal;
    cout.precision(2);
    cout << "   Total Worth: $" << totalVal << '\n';
    
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topVal(const Stock &s) const {
    return s.totalVal > totalVal ? s : *this;
}
