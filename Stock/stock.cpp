//
//  stock.cpp
//  Stock
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "stock.h"
#include <iostream>

Stock::Stock(const std::string & co, long n, double pr) {
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

Stock::Stock() {
    company = "no name";
    shares = 0;
    shareVal = 0.0;
    totalVal = 0.0;
}

void Stock::acquire(const std::string & co, long n, double pr) {
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

void Stock::buy(long num, double price) {
    if(num < 0) {
        std::cout << "Number of shares can't be negative. Transaction is aborted.\n";
    } else {
        shares += num;
        shareVal = price;
        setTotal();
    }
}

void Stock::sell(long num, double price) {
    if(num < 0) {
        std::cout << "Number of shares can't be negative. Transaction is aborted.\n";
    } else if(num > shares){
        std::cout << "You can't sell more than you have! Transaction is aborted.\n";
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

void Stock::show() {
    using std::cout;
    using std::ios_base;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    
    cout << "Company: " << company << " Shares: " << shares << '\n';
    cout << "   Share Price: $" << shareVal;
    cout.precision(2);
    cout << "   Total worth: $" << totalVal << '\n';
    
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

Stock::~Stock() {
    std::cout << "Bye " << company << "!\n";
}
