//
//  Brass.cpp
//  Brass
//
//  Created by stone on 2020/2/18.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "Brass.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precision;
format setFormat();
void restore(format f, precision p);

Brass::Brass(const string & s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt) {
    if(amt < 0) {
        cout << "Negative deposit isn't allowed; " << "deposit cancelled.\n";
    } else {
        balance += amt;
    }
}

void Brass::Withdraw(double amt) {
    format initialState = setFormat();
    precision prec = cout.precision(2);
    
    if(amt < 0) {
        cout << "Negative withdraw isn't allowed; " << "withdraw cancelled.\n";
    } else if(amt <= balance) {
        balance -= amt;
    } else {
        cout << "Withdraw amount of $" << amt << " exceeds your balance.\n";
        cout << "Withdraw cancelled.\n";
    }
    restore(initialState, prec);
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    format initialState = setFormat();
    precision prec = cout.precision(2);
    
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}

BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r) : Brass(s, an, bal){
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba){
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcct() const {
    format initialState = setFormat();
    precision prec = cout.precision(2);
    
    Brass::ViewAcct();
    cout << "MaxLoan: $" << maxLoan << endl;
    cout << "Owe to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: $" << rate * 100 << "%" << endl;
    restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
    format initialState = setFormat();
    precision prec = cout.precision(2);
    
    double bal = Balance();
    if(amt < 0) {
        cout << "Negative withdraw isn't allowed; withdraw cancelled.\n";
    } else if(amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    
    restore(initialState, prec);
}

format setFormat() {
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precision p) {
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}

