//
// Created by jerrywang on 2020/5/12.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#ifndef LAB7_AVLTREE_NODE_H
#define LAB7_AVLTREE_NODE_H


#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    int count;
    int nodeHeight;
    Node* left;
    Node* right;
    Node* parent;
    Node(string data);
    void increaseCount();
    void decreaseCount();
};


#endif //LAB7_AVLTREE_NODE_H
