//
// Created by jerrywang on 2020/5/7.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#ifndef CHALLENGE3_BST_NODE_H
#define CHALLENGE3_BST_NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    int count;
    Node* left;
    Node* right;
    Node(string data);
    void increaseCount();
    void decreaseCount();
};


#endif //CHALLENGE3_BST_NODE_H
