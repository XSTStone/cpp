//
//  main.cpp
//  WorkerMI
//
//  Created by stone on 2020/2/22.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include <string>
#include "WorkerMI.hpp"
const int SIZE = 5;

int main(int argc, const char * argv[]) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;
    
    Worker* lolas[SIZE];
    
    int ct;
    for (ct = 0; ct < SIZE;++ct) {
        char choice;
        cout << "Enter the employee category:\n" << "w: waiter    s:singer    t:singing waiter    q:quit\n";
        cin >> choice;
        while (strchr("wtsq", choice) == nullptr) {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if(choice == 'q') {
            break;
        }
        switch (choice) {
            case 'w':
                lolas[ct] = new Waiter;
                break;
            case 's':
                lolas[ct] = new Singer;
                break;
            case 't':
                lolas[ct] = new SingingWaiter;
                break;
            default:
                break;
        }
        cin.get();
        lolas[ct]->Set();
    }
    
    cout << "\nHere is your stuff:\n";
    int i;
    for (i = 0;i < SIZE;++i) {
        cout << endl;
        lolas[i]->Show();
    }
    for (i = 0;i < SIZE;++i) {
        delete lolas[i];
    }
    cout << "Done.\n";
    
    return 0;
}
