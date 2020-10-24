//
// Created by jerrywang on 2020/4/5.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#ifndef LAB2_DOUBLY_LINKED_INTLIST_H
#define LAB2_DOUBLY_LINKED_INTLIST_H

#include <iostream>
using namespace std;
struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};
class IntList {
public:
    IntList();
    ~IntList();
    void push_front(int value);
    void pop_front();
    void push_back(int value);
    void pop_back();
    bool empty() const;
    friend ostream& operator<< (ostream& out, const IntList& rhs);
    void printReverse() const;
private:
    IntNode* dumHead;
    IntNode* dumTail;
};


#endif //LAB2_DOUBLY_LINKED_INTLIST_H
