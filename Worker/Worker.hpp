//
//  Worker.hpp
//  Worker
//
//  Created by stone on 2020/2/22.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef Worker_hpp
#define Worker_hpp

#include <string>

class Worker {
private:
    std::string fullName;
    long id;
public:
    Worker() : fullName("no one"), id(0L) {}
    Worker(const std::string & s, long n) : fullName(s), id(n) {}
    virtual ~Worker() = 0;
    virtual void Set();
    virtual void Show() const;
};

class Waiter : public Worker {
private:
    int panache;
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string & s, long n, int p = 0) : Worker(s, n), panache(p) {}
    Waiter(const Worker & wk, int p = 0) : Worker(wk), panache(p) {}
    void Set();
    void Show() const;
};

class Singer : public Worker {
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
private:
    static char* pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string & s, long n, int v = other) : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other) : Worker(wk), voice(v) {}
    void Set();
    void Show() const;
};

#endif /* Worker_hpp */
