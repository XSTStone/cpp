//
//  main.cpp
//  Stock_3.0
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "stock_3.hpp"

const int STKS = 4;

int main(int argc, const char * argv[]) {
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Object", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };
    
    std::cout << "Stock Holding:\n";
    for (int i = 0;i < STKS;++i) {
        stocks[i].show();
    }
    const Stock* top = &stocks[0];
    for (int i = 1;i < STKS;++i) {
        top = &top->topVal(stocks[i]);
    }
    std::cout << "\nMost valuable holding:\n";
    top->show();
    
    return 0;
}
