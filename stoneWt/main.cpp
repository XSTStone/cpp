//
//  main.cpp
//  stoneWt
//
//  Created by stone on 2020/2/15.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "stoneWt.hpp"
using std::cout;

void display(const Stonewt & st, int n);

void printTips();

int main(int argc, const char * argv[]) {
    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);
    Stonewt poppins(9, 2.8);
    int mode;
    printTips();
    
    while (std::cin >> mode) {
        while (std::cin.get() != '\n') {
            continue;
        }
        if(mode == 1) {
            cout << "The celebrity weighed ";
            incognito.showStn();
            cout << "The detective weighed ";
            wolfe.showStn();
            cout << "The President weighed ";
            taft.showLbs();
            incognito = 276.8;
            taft = 325;
            cout << "After dinning, the celebrity weighed ";
            incognito.showStn();
            cout << "After dinning, the President weighed ";
            taft.showLbs();
            display(taft, 2);
            cout << "The wrestler weighed even more.\n";
            display(422, 2);
            cout << "No stone left unearned.\n";
        } else if(mode == 2) {
            double pWt = poppins;
            cout << "Convert to double => ";
            cout << "Poppins: " << pWt << " pounds.\n";
            cout << "Convert to int => ";
            cout << "Poppins: " << int(poppins) << " pounds.\n";
        } else if(mode == 3) {
            Stonewt total;
            total = incognito + taft;
            total.showStn();
        }
        printTips();
    }
    
    return 0;
}

void display(const Stonewt & st, int n) {
    for (int i = 0;i < n;++i) {
        cout << "Wow! ";
        st.showStn();
    }
}

void printTips() {
    cout << "Enter 1 to mode 1.\n" << "Enter 2 to mode 2.\n" << "Enter 3 to mode 3.\n" <<"Enter q to quit.\n";
}
