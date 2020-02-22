//
//  WorkerMI.hpp
//  WorkerMI
//
//  Created by stone on 2020/2/22.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef WorkerMI_hpp
#define WorkerMI_hpp

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Worker {
private:
    string fullName;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullName("no one"), id(0L) {}
    Worker(const string & s, long n) : fullName(s), id(n) {}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker {
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const Worker & wk, int n = 0) : Worker(wk), panache(n) {}
    Waiter(const string & s, long n, int p = 0) : Worker(s, n), panache(p) {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker {
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    int voice;
    static char* pv[Vtypes];
public:
    Singer() : Worker(), voice(other) {}
    Singer(const string & s, long n, int v = other) : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other) : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

class SingingWaiter : public Waiter, public Singer {
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {}
    SingingWaiter(const string & s, long n, int v = other, int p = 0) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
    SingingWaiter(const Worker & wk, int v = other, int p = 0) : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter & wt, int v = other) : Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer & sg, int p = 0) : Worker(sg), Waiter(sg, p), Singer(sg) {}
    void Set();
    void Show() const;
};

#endif /* WorkerMI_hpp */
