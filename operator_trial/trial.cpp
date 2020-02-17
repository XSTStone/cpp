//
//  trial.cpp
//  operator_trial
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "trial.hpp"
#include <iostream>

Stack::Stack() {
    for (int i = 0;i < MAX;++i) {
        stack[i] = 0;
    }
    pointer = 0;
}

void Stack::printTips() {
    using std::cout;
    using std::endl;
    cout << "输入 A 添加数字至栈顶\n" << "输入 P 弹出栈顶数字\n" << "输入 S 查看栈\n" << "输入 Q 退出程序.\n";
}

void Stack::showAllNumbers() {
    std::cout << "栈：\n";
    int i = pointer - 1;
//    std::cout << "pointer = " << pointer << std::endl;
    for (;i >= 0;--i) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}

bool Stack::isfull() const {
    return pointer == MAX;
}

bool Stack::isempty() const {
    return pointer == 0;
}

bool Stack::operator+(const Item & item) {
    if(pointer < MAX) {
        stack[pointer++] = item;
        return true;
    } else {
        return false;
    }
}

bool Stack::operator-(Item & item) {
    if(pointer >= 0) {
        item = stack[--pointer];
        return true;
    } else {
        return false;
    }
}
