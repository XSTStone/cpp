//
//  trial.hpp
//  operator_trial
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef trial_hpp
#define trial_hpp
typedef unsigned long Item;

class Stack {
private:
    enum {MAX = 10};
    Item stack[MAX];
    int pointer;
public:
    Stack();
    void printTips();
    void showAllNumbers();
    bool isfull() const;
    bool isempty() const;
    bool operator+(const Item & item);
    bool operator-(Item & item);
};


#endif /* trial_hpp */
