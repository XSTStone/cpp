//
//  main.cpp
//  vector
//
//  Created by stone on 2020/2/15.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.hpp"

int main(int argc, const char * argv[]) {
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): \n";
    while (cin >> target) {
        cout << "Enter step length:\n";
        if(!(cin >> dstep)) {
            cout << "OK\n";
            break;
        }
        
        while (result.magVal() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps ++;
        }
        cout << "After " << steps << " steps, the subject has the following location:\n";
        cout << result;
        result.modePolar();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = " << result.magVal() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): \n";
     }
    cout << "Bye.\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    
    return 0;
}
