//
//  Brass.hpp
//  BrassVirtual
//
//  Created by stone on 2020/2/18.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef Brass_hpp
#define Brass_hpp
#include <string>

class Brass {
private:
    std::string fullName;
    long acctNum;
    double balance;
public:
    Brass(const std::string & s = "none", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

class BrassPlus : public Brass {
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string & s = "NullBody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m);
    void ResetRate(double r);
    void ResetOwes() { owesBank = 0; }
};

#endif /* Brass_hpp */
