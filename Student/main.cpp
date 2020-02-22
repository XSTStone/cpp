//
//  main.cpp
//  Student
//
//  Created by stone on 2020/2/21.
//  Copyright © 2020 Stone. All rights reserved.
//

#include <iostream>
#include "student.hpp"

using std::cin;
using std::cout;
using std::endl;

void set(Student & stu, int n);
const int pupils = 3;
const int quizzes = 5;

int main(int argc, const char * argv[]) {
    Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
    for (int i = 0;i < pupils;++i) {
        set(ada[i], quizzes);
    }
    cout << "Students List:\n";
    for (int i = 0;i < pupils;++i) {
        cout << ada[i].Name() << endl;
    }
    cout << "Scores:\n";
    for (int i = 0;i < pupils;++i) {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average();
    }
    cout << "Done.\n";
    
    return 0;
}

void set(Student & stu, int n) {
    cout << "Please enter the student's name: ";
    getline(cin, stu);
    cout << "Please enter " << n << " quiz score:\n";
    for (int i = 0;i < n;++i) {
        cin >> stu[i];
    }
    while (cin.get() != '\n')
        continue;
}
