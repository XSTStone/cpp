//
//  coordin.h
//  C++
//
//  Created by stone on 2020/2/13.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef coordin_h
#define coordin_h

#include <string>

namespace pers {
struct Person {
    std::string fname;
    std::string lname;
};
void getPerson (Person &);
void showPerson (Person &);
}

namespace debts {
using namespace pers;
struct Debt {
    Person name;
    double amount;
};
void getDebt (Debt &);
void showDebt (const Debt &);
double sumDebts (const Debt ar[], int n);
}

#endif /* coordin_h */
