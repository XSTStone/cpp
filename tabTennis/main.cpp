//
//  main.cpp
//  tabTennis
//
//  Created by stone on 2020/2/17.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "tableTennis.hpp"

int main(int argc, const char * argv[]) {
    tableTennisPlayer player1("Chuck", "Blizzard", false);
    ratedPlayer rplayer1(1140, "Mallory", "Duck", true);
    player1.Name();
    if(player1.HasTable()) {
        std::cout << ": has a table.\n";
    } else {
        std::cout << ": hasn't a table.\n";
    }
    rplayer1.Name();
    if(rplayer1.HasTable()) {
        std::cout << ": has a table.\n";
    } else {
        std::cout << ": hasn't a table.\n";
    }
    std::cout << "Name: ";
    rplayer1.Name();
    std::cout << "; Rating: " << rplayer1.Rating() << std::endl;
    
    ratedPlayer rplayer2(1212, player1);
    std::cout << "Name: ";
    rplayer2.Name();
    std::cout << "; Rating: " << rplayer2.Rating() << std::endl;
    
    return 0;
}
