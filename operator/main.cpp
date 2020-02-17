//
//  main.cpp
//  operator
//
//  Created by stone on 2020/2/14.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "operator.hpp"

int main(int argc, const char * argv[]) {
    using std::cout;
    using std::ostream;
    using std::endl;
    
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
    
    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "Tosca * 10: " << tosca * 10.0 << endl;
    
    return 0;
}
