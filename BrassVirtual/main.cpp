//
//  main.cpp
//  BrassVirtual
//
//  Created by stone on 2020/2/18.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include <string>
#include "Brass.hpp"
const int CLIENTS = 4;

int main(int argc, const char * argv[]) {
    using std::cin;
    using std::cout;
    using std::endl;
    
    Brass* clientsPointer[CLIENTS];
    std::string temp;
    long tempNum;
    double tempBal;
    char kind;
    
    for (int i = 0;i < CLIENTS;++i) {
        cout << "Enter client's name: ";
        getline(cin, temp);
        cout << "Enter client's account number: ";
        cin >> tempNum;
        cout << "Enter opening balance: ";
        cin >> tempBal;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2')) {
            cout << "Enter either 1 or 2: ";
        }
        if(kind == '1') {
            clientsPointer[i] = new Brass(temp, tempNum, tempBal);
        } else {
            double tempMax, tempRate;
            cout << "Enter the overDraft limit: $";
            cin >>tempMax;
            cout << "Enter the interest rate as a decimal fraction: ";
            cin >> tempRate;
            clientsPointer[i] = new BrassPlus(temp, tempNum, tempBal, tempMax, tempRate);
        }
        while (cin.get() != '\n') {
            continue;
        }
    }
    cout << endl;
    for (int i = 0;i < CLIENTS;++i) {
        clientsPointer[i]->ViewAcct();
        cout << endl;
    }
    for (int i = 0;i < CLIENTS;++i) {
        delete clientsPointer[i];
    }
    cout << "Done\n";
    return 0;
}
