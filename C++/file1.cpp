//
//  file1.cpp
//  C++
//
//  Created by stone on 2020/2/13.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "coordin.h"

namespace pers {
using std::cout;
using std::cin;
void getPerson (Person &referencePerson) {
    cout << "Enter first name: ";
    cin >> referencePerson.fname;
    cout << "Enter last name: ";
    cin >> referencePerson.lname;
}
void showPerson (Person &referencePerson) {
    cout << referencePerson.lname << ", " << referencePerson.fname << std::endl;
}
}

namespace debts {
using std::cin;
using std::cout;
void getDebt (Debt &referenceDebt) {
    getPerson(referenceDebt.name);
    cout << "Enter the debt: ";
    cin >> referenceDebt.amount;
}
void showDebt (const Debt &referenceDebt) {
    Person name = referenceDebt.name;
    showPerson(name);
    cout << ": $" << referenceDebt.amount << std::endl;
}
double sumDebts (const Debt ar[], int n) {
    double total = 0;
    for (int i = 0;i < n;++i) {
        total += ar[i].amount;
    }
    return total;
}
}
