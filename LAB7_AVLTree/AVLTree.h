//
// Created by jerrywang on 2020/5/12.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#ifndef LAB7_AVLTREE_AVLTREE_H
#define LAB7_AVLTREE_AVLTREE_H

#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"
using namespace std;
class AVLTree {
private:
    Node* root;
public:
    AVLTree();
    void insert(const string&);
    //Return the balance factor of a given node.
    int balanceFactor(Node*);
    //Traverse and print the tree in inorder notation.
    // Print the string followed by its balance factor in parentheses followed by a , and one space.
    void printBalanceFactors();
    void visualizeTree(const string&);
    int height(const string &key) const;
    int height(Node*)const;
private:
    //Find and return the closest unbalanced node (with balance factor of 2 or -2) to the inserted node.
    Node* findUnbalancedNode(Node*);
    void rotate(Node*);
    Node* rotateLeft(Node*);
    Node* rotateRight(Node*);
    void printBalanceFactors(Node*);
    void visualizeTree(ofstream&, Node*);
    void updateHeight(Node* node);
};


#endif //LAB7_AVLTREE_AVLTREE_H
