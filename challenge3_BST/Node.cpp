//
// Created by jerrywang on 2020/5/7.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#include "Node.h"
#include <string>
#include <iostream>
using namespace std;
Node::Node(string data){
    this->data = data;
    count = 0;
    left = nullptr;
    right = nullptr;
}
void Node::increaseCount() {
    count++;
}
void Node::decreaseCount() {
    count--;
}