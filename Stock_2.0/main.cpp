//
//  main.cpp
//  Stock_2.0
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "stock_2.hpp"

int main(int argc, const char * argv[]) {
    {
        using std::cout;
        cout << "Using constructors to create new objects.\n";
        Stock stock1{"NanoSmart", 12, 20.0};
        stock1.show();
        Stock stock2 = Stock{"Apple", 2, 2.0};
        stock2.show();
        
        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();
        
        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("Nifty Foods", 10, 50.0);
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done\n";
    }
    return 0;
}
