//
//  main.cpp
//  Worker
//
//  Created by stone on 2020/2/22.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "Worker.hpp"

const int LIMIT = 4;

int main(int argc, const char * argv[]) {
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    Waiter w_temp;
    Singer s_temp;
    
    Worker* pw[LIMIT] = {&bob, &bev, &w_temp, &s_temp};
    
    int i;
    for (i = 2;i < LIMIT;++i) {
        pw[i]->Set();
    }
    for(i = 0;i < LIMIT;++i) {
        pw[i]->Show();
        std::cout << std::endl;
    }
    
    return 0;
}
