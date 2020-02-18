//
//  tableTennis.cpp
//  tabTennis
//
//  Created by stone on 2020/2/17.
//  Copyright © 2020 Stone. All rights reserved.
//

#include "tableTennis.hpp"
#include <iostream>

tableTennisPlayer::tableTennisPlayer(const string & fn, const string & ln, bool ht) : firstName(fn), lastName(ln), hasTable(ht) {}

void tableTennisPlayer::Name() const {
    std::cout << lastName << ", " << firstName;
}

ratedPlayer::ratedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) : tableTennisPlayer(fn, ln, ht) {
    rating = r;
}

ratedPlayer::ratedPlayer(unsigned int r, const tableTennisPlayer & tp) : tableTennisPlayer(tp) {
    rating = r;
}
