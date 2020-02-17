//
//  main.cpp
//  C++_1
//
//  Created by stone on 2020/2/13.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>

using namespace std;
namespace Jill {
double fetch;
void show() {
    cout << "Jill's fetch: " << fetch << endl;
}
}

//namespace Jack {
//double fetch;
//}

double fetch;
void show() {
    cout << "All's fetch: " << ::fetch << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    double fetch;
    using namespace Jill;
    cin >> fetch;
    cin >> ::fetch;
    cin >> Jill::fetch;
    ::show();
    Jill::show();
    return 0;
}
