//
// Created by jerrywang on 2020/4/5.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#include "IntList.h"
#include <iostream>
using namespace std;
IntList::IntList(){
    dumHead = new IntNode(0);
    dumTail = new IntNode(0);
//    dumHead->prev = nullptr;
//    dumTail->next = nullptr;
    dumHead->next = dumTail;
    dumTail->prev = dumHead;
}
IntList::~IntList(){
    IntNode* curr;
    curr = dumHead->next;
    IntNode* temp;
    while (curr!= dumTail){
        dumHead->next = curr->next;
        temp = curr->next;
        temp->prev = dumHead;
        delete curr;
        curr = temp;
    }
}
void IntList::push_front(int value) {
    IntNode* temp;
    IntNode* curr = dumHead->next;
    temp = new IntNode(value);
    temp->next = curr;
    dumHead->next = temp;
    temp->prev = dumHead;
    curr->prev = temp;
    if (dumTail->prev == dumHead){
        dumHead->next = temp;
        temp->next = dumTail;
        dumTail->prev = temp;
        temp->prev = dumHead;
    }
}
void IntList::pop_front() {
    if (empty()){
        return;
    }
    else{
        if (dumHead->next->next == dumTail){
            IntNode* node = dumHead->next;
            dumHead->next = dumTail;
            dumTail->prev = dumHead;
            delete node;
        }
        else{
            IntNode* curr = dumHead->next;
            IntNode* temp = curr->next;
            dumHead->next = temp;
            temp->prev = dumHead;
            delete curr;
        }
    }
}
void IntList::push_back(int value) {
    IntNode* curr = dumTail->prev;
    IntNode* temp = new IntNode(value);
    curr->next = temp;
    temp->next = dumTail;
    dumTail->prev = temp;
    temp->prev = curr;
    if (dumTail->prev == dumHead){
        dumHead->next = temp;
        temp->next = dumTail;
        temp->prev = dumHead;
        dumTail->prev = temp;
    }
}
void IntList::pop_back() {
    if (empty()){
        return;
    }
    else{
        if (dumHead->next->next == dumTail){
            IntNode* node = dumHead->next;
            dumHead->next = dumTail;
            dumTail->prev = dumHead;
            delete node;
        }
        else{
            IntNode* temp = dumTail->prev;
            IntNode* curr = temp->prev;
            curr->next = temp->next;
            dumTail->prev = curr;
            delete temp;

        }
    }
}
bool IntList::empty() const {
    if (dumTail->prev == dumHead){
        return true;
    }
    return false;
}
ostream& operator<< (ostream& out, const IntList& list){
    IntNode* temp;
    temp = list.dumHead->next;
    while (temp!= list.dumTail){
        out << temp->data;
        temp = temp->next;
        if (temp!= list.dumTail){
            out << " ";
        }
    }
    return out;
}
void IntList::printReverse() const {
    IntNode* temp;
    temp = dumTail->prev;
    while (temp!= dumHead){
        cout << temp->data;
        temp = temp->prev;
        if (temp != dumHead){
            cout << " ";
        }
    }
}