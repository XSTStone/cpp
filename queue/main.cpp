//
//  main.cpp
//  queue
//
//  Created by stone on 2020/2/16.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Queue.hpp"
const int MIN_PER_HR = 60;

bool newCustomer(double x);

int main(int argc, const char * argv[]) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));
    
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);
    
    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cycleLimit = MIN_PER_HR * hours;
    
    cout << "Enter the average number of customers per hour: ";
    double perHour;
    cin >> perHour;
    double minPerCust;
    minPerCust = MIN_PER_HR / perHour;
    
    Item temp;
    long turnAways = 0;
    long customers = 0;
    long served = 0;
    long sumLine = 0;
    long waitTime = 0;
    long lineWait = 0;
    
    for (int cycle = 0;cycle < cycleLimit;++cycle) {
        if(newCustomer(minPerCust)) {
            if(line.isfull()) {
                turnAways++;
            } else {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if(waitTime <= 0 && !line.isempty()) {
            line.dequeue(temp);
            waitTime = temp.ptime();
            lineWait += cycle - temp.when();
            served++;
        }
        if(waitTime > 0) {
            waitTime--;
        }
        sumLine += line.queuecount();
    }
    
    if(customers > 0) {
        cout << "Customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "          turnaway: " << turnAways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sumLine / cycleLimit << endl;
        cout << " average wait time: " << (double) lineWait / served << " minutes\n";
    } else {
        cout << "No customers!\n";
    }
    cout << "Done!\n";
 
    return 0;
}

bool newCustomer(double x) {
    bool flag = (std::rand() * x / RAND_MAX < 1);
    std::cout << "flag = " << flag << std::endl;
    return flag;
}
