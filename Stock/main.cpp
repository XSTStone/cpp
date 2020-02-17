//
//  main.cpp
//  Stock
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "stock.h"

int main(int argc, const char * argv[]) {
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout.precision(3);
    Stock fluffyTheCat;
    fluffyTheCat.acquire("NanoSmart", 20, 12.50);
    fluffyTheCat.show();
    fluffyTheCat.buy(15, 18.125);
    fluffyTheCat.show();
    fluffyTheCat.sell(400, 20.00);
    fluffyTheCat.show();
    fluffyTheCat.buy(30000, 40.125);
    fluffyTheCat.show();
    fluffyTheCat.sell(30000, 0.125);
    fluffyTheCat.show();
    return 0;
}
