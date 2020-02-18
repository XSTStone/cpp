//
//  tableTennis.hpp
//  tabTennis
//
//  Created by stone on 2020/2/17.
//  Copyright © 2020 Stone. All rights reserved.
//

#ifndef tableTennis_hpp
#define tableTennis_hpp
#include <string>
using std::string;

class tableTennisPlayer {
private:
    string firstName;
    string lastName;
    bool hasTable;
public:
    tableTennisPlayer(const string & fn = "none", const string & ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};

class ratedPlayer : public tableTennisPlayer {
private:
    unsigned int rating;
public:
    ratedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
    ratedPlayer(unsigned int r, const tableTennisPlayer & tp);
    unsigned int Rating() const { return rating; }
    void ResetTable (unsigned int r) { rating = r; }
};

#endif /* tableTennis_hpp */
