//
//  main.cpp
//  operator_trial
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "trial.hpp"

int main(int argc, const char * argv[]) {
    Stack sk;
    sk.printTips();
    char ch;
    while (std::cin >> ch && toupper(ch) != 'Q') {
        while (std::cin.get() !='\n') {
            continue;
        }
        unsigned long num;
        switch (ch) {
            case 'a':
            case 'A':
                std::cout << "添加一个数字到栈顶：\n";
                std::cin >> num;
                if(sk + num) {
                    std::cout << "添加成功！\n\n";
                } else {
                    std::cout << "添加失败，栈已满\n\n";
                }
                break;
            case 'p':
            case 'P':
                unsigned long po;
                if(sk - po) {
                    std::cout << po << " 已被弹出栈顶\n\n";
                    break;
                } else {
                    std::cout << "弹出失败，栈已空\n\n";
                    break;
                }
            case 's':
            case 'S':
                sk.showAllNumbers();
                break;
                
            default:
                break;
        }
        sk.printTips();
    }
    return 0;
}
