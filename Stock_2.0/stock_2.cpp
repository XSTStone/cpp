//
//  stock_2.cpp
//  Stock_2.0
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "stock_2.hpp"
#include <iostream>

Stock::Stock() {
    std::cout << "Default constructor called.\n";
    company = "no name";
    shares = 0;
    shareVal = 0.0;
    totalVal = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr) {
    std::cout << "Constructor using " << co << " called.\n";
    company = co;
    
    if(n < 0) {
        std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
        shares = 0;
    } else {
        shares = n;
    }
    shareVal = pr;
    setTotal();
}

Stock::~Stock() {
    std::cout << "Bye, " << company << "!\n";
}

void Stock::buy(long num, double price) {
    if(num < 0) {
        std::cout << "Number of shares purchased can't be negative." << " Transaction is absorted.\n";
    } else {
        shares += num;
        shareVal = price;
        setTotal();
    }
}

void Stock::sell(long num, double price) {
    if(num < 0) {
        std::cout << "Number of shares purchased can't be negative." << " Transaction is absorted.\n";
    } else if(num > shares) {
        std::cout << "You can't sell more than you have!" << " Transaction is absorted.\n";
    } else {
        shares -= num;
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
    using std::endl;
    using std::ios_base;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    
    cout << "Company: " << company << " Shares: " << shares << '\n';
    cout << "   Share Price: $" << shareVal;
    cout.precision(2);
    cout << "   Total Worth: $" << totalVal << endl;
    
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

const Stock & Stock::topVal(const Stock & s) const {
    return s.totalVal > totalVal ? s : *this;
}
