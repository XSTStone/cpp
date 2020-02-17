//
//  main.cpp
//  string
//
//  Created by stone on 2020/2/15.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "stringBad.hpp"
#include "string.hpp"
using std::cout;

void callMe_1(StringBad &);
void callMe_2(StringBad);
void callMe_1(String &);
void callMe_2(String);
void funStringBad();
void funStringGood();

const int ArSize = 10;
const int MaxLen = 81;

int main(int argc, const char * argv[]) {
    using std::endl;
    using std::cin;
    
    String name;
    cout << "Hi, what's your name?\n";
    cin >> name;
    
    cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
    String sayings[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0;i < ArSize;++i) {
        cout << i+1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if(!cin || temp[0] == '\0') {
            break;
        } else {
            sayings[i] = temp;
        }
    }
    int total = i;
    
    if(total > 0) {
        cout << "Here are your sayings:\n";
        for (i = 0;i < total;++i) {
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        }
        
        int shortest = 0;
        int first = 0;
        for (i = 1;i < total;++i) {
            if(sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if(sayings[i] < sayings[first])
                first = i;
        }
        
        cout << "Shortest saying:\n" << sayings[shortest] << endl;
        cout << "First alphabetically:\n" << sayings[first] << endl;
        cout << "This program used " << String::howMany() << " String objects. Bye.\n";
    } else {
        cout << "No input! Bye.\n";
    }
    
    return 0;
}

void callMe_1(StringBad & rsb) {
    cout << "String passed by reference:\n";
    cout << "   \"" << rsb << "\"\n";
}

void callMe_2(StringBad sb) {
    cout << "String passed by value:\n";
    cout << "   \"" << sb << "\"\n";
}

void callMe_1(String & rsb) {
    cout << "String passed by reference:\n";
    cout << "   \"" << rsb << "\"\n";
}

void callMe_2(String sb) {
    cout << "String passed by value:\n";
    cout << "   \"" << sb << "\"\n";
}

void funStringBad() {
    using std::endl;
    cout << "Starting an inner block.\n";
    StringBad headline_1("Celery Stalks at Midnight");
    StringBad headline_2("Lettuce Prey");
    StringBad sports("Spinach Leaves Bowl for Dollars");
    cout << "headline_1: " << headline_1 << endl;
    cout << "headline_2: " << headline_2 << endl;
    cout << "sports: " << sports << endl;
    callMe_1(headline_1);
    cout << "headline_1: " << headline_1 << endl;
    callMe_2(headline_2);
    cout << "headline_2: " << headline_2 << endl;
    cout << "Initialize one object to another:\n";
    StringBad sailor = sports;
    cout << "sailor: " << sailor << endl;
    cout << "Assign one object to another:\n";
    StringBad knot;
    knot = headline_1;
    cout << "knot: " << knot << endl;
    cout << "Exiting the block.\n";
}

void funStringGood() {
    using std::endl;
    cout << "Starting an inner block.\n";
    String headline_1("Celery Stalks at Midnight");
    String headline_2("Lettuce Prey");
    String sports("Spinach Leaves Bowl for Dollars");
    cout << "headline_1: " << headline_1 << endl;
    cout << "headline_2: " << headline_2 << endl;
    cout << "sports: " << sports << endl;
    callMe_1(headline_1);
    cout << "headline_1: " << headline_1 << endl;
    callMe_2(headline_2);
    cout << "headline_2: " << headline_2 << endl;
    cout << "Initialize one object to another:\n";
    String sailor = sports;
    cout << "sailor: " << sailor << endl;
    cout << "Assign one object to another:\n";
    String knot;
    knot = headline_1;
    cout << "knot: " << knot << endl;
    cout << "Exiting the block.\n";
}
