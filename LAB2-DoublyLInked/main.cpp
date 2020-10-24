//
//  main.cpp
//  LAB2_DOUBLY_LINKED
//
//  Created by jerrywang on 2020/4/5.
//  Copyright © 2020 anniewang. All rights reserved.
//

#include <iostream>
#include "IntList.h"
using namespace std;
int main(int argc, const char * argv[]) {
    IntList list1;
    cout << list1 << endl;
    list1.push_front(1);
    cout << list1 << endl;
    list1.push_front(2);
    cout << list1 << endl;
    list1.push_front(3);
    cout << list1 << endl;
    list1.push_back(4);
    cout << list1 << endl;
    list1.push_back(5);
    cout << list1 << endl;
    list1.push_back(6);
    cout << list1 << endl;
    list1.printReverse();
    cout << endl;
    list1.pop_front();
    list1.pop_front();
    cout << list1 << endl;
    list1.pop_back();
    list1.pop_back();
    cout << list1 << endl;
    return 0;

}