//
//  main.cpp
//  stack
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include <cctype>
#include "stack.hpp"

int main(int argc, const char * argv[]) {
    using namespace std;
    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n" << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q') {
        while (cin.get() != '\n') {
            continue;
        }
        if(!isalpha(ch)) {
            cout << '\a';
            continue;
        }
        switch (ch) {
            case 'A':
            case 'a':
                cout << "Enter a PO number to add: ";
                cin >> po;
                if(st.isfull()) {
                    cout << "Stack is already full.\n";
                } else {
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':
                if(st.isempty()) {
                    cout << "Stack is already empty.\n";
                } else {
                    st.pop(po);
                    cout << "PO #" << po << " popped.\n";
                }
                break;
            default:
                break;
        }
        cout << "Please enter A to add a purchase order,\n" << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye.\n";
    return 0;
}
