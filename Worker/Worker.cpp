//
//  Worker.cpp
//  Worker
//
//  Created by stone on 2020/2/22.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "Worker.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


Worker::~Worker() {}

void Worker::Set() {
    cout << "Enter worker's name: ";
    getline(cin, fullName);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
        continue;
}

void Worker::Show() const {
    cout << "Name: " << fullName << endl;
    cout << "ID: " << id << endl;
}

//Waiter::~Waiter() {}

void Waiter::Set() {
    Worker::Set();
    cout << "Enter waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n')
        continue;
}

void Waiter::Show() const {
    cout << "Category: waiter\n";
    Worker::Show();
    cout << "Panache rating: " << panache << endl;
}

char* Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set() {
    Worker::Set();
    cout << "Enter the number for singer's vocal range:\n";
    int i;
    for (i = 0;i < Vtypes;++i) {
        cout << i << ": " << pv[i] << " ";
        if(i % 4 == 3)
            cout << endl;
    }
    if(i % 4 != 0) {
        cout << endl;
    }
    while (cin >> voice && (voice < 0 || voice >= Vtypes)) {
        cout << "Please enter a value ≥ 0 and < " << Vtypes << endl;
    }
    while (cin.get() != '\n') {
        continue;
    }
}

void Singer::Show() const {
    cout << "Catogory: singer\n";
    Worker::Show();
    cout << "Vocal range: " << pv[voice] << endl;
}
