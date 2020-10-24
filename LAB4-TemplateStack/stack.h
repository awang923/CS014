//
// Created by jerrywang on 2020/4/19.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#ifndef LAB4_TEMPLATESTACK_STACK_H
#define LAB4_TEMPLATESTACK_STACK_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

const unsigned MAX_SIZE = 20;
template<typename T>
class stack {
private:
    T data[MAX_SIZE];
    unsigned size;
public:
    stack();
    void push(T val);
    void pop();
    T top();
    bool empty();
};
#endif //LAB4_TEMPLATESTACK_STACK_H

template<typename T>
stack<T>::stack(){
//    data(0);
    size = 0;
}
template<typename T>
void stack<T>::push(T val){
    if (size == MAX_SIZE){
        throw overflow_error("Called push on full stack.");
    }
    data[size] = val;
    size++;
}
template<typename T>
void stack<T>::pop(){
    if (size <= 0){
        throw out_of_range("Called pop on empty stack.");
    }
    size--;
}
template<typename T>
T stack<T>::top(){
    if(size <= 0){
        throw out_of_range("Called top on empty stack.");
    }
    return data[size - 1];
}
template<typename T>
bool stack<T>::empty(){
    if (size == 0){
        return true;
    }
    return false;
}