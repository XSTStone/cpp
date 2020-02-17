//
//  main.cpp
//  placenew
//
//  Created by stone on 2020/2/16.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class JustTesting {
private:
    string words;
    int number;
public:
    JustTesting(const string & s = "Just Testing", int n = 0) {
        words = s;
        number = n;
        cout << words << " constructed\n";
    }
    
    ~JustTesting() {
        cout << words << " destroyed\n";
    }
    
    void show() const {
        cout << words << ", " << number << endl;
    }
};

int main(int argc, const char * argv[]) {
    char* buffer = new char[BUF];
    
    JustTesting* p1;
    JustTesting* p2;
    p1 = new (buffer) JustTesting;
    p2 = new JustTesting("Heap1", 20);
    
    cout << "Memory block addresses:\n" << "buffer: " << (void*) buffer << "    heap: " << p2 << endl;
    cout << "Memory contents:\n";
    cout << p1 << ": ";
    p1->show();
    cout << p2 << ": ";
    p2->show();
    
    JustTesting* p3;
    JustTesting* p4;
    p3 = new (buffer + sizeof(JustTesting)) JustTesting("Better idea", 6);
    p4 = new JustTesting("Heap2", 10);
    
    cout << "Memery contents:\n";
    cout << p3 << ": ";
    p3->show();
    cout << p4 << ": ";
    p4->show();
    
    delete p2;
    delete p4;
    p3->~JustTesting();
    p1->~JustTesting();
    delete[] buffer;
    cout << "Done\n";
    
    return 0;
}
