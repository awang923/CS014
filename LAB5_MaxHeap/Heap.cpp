//
// Created by jerrywang on 2020/4/29.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#include "Heap.h"
#include <iostream>
#include <utility>
using namespace std;

Heap::Heap(){
    numItems = 0;
}
void Heap::enqueue(PrintJob *pj) {
    if (numItems+1 <= MAX_HEAP_SIZE){
        if (numItems == 0){
            arr[0] = pj;
            numItems++;
        }
        else{
            int x = numItems;
            while (x > 0 && arr[(x-1)/2]->getPriority() < pj ->getPriority()){
                arr[x] = arr[(x-1)/2];

                x = (x-1)/2;
            }
            arr[x] = pj;
            ++numItems;
//            while (pj->getPriority() > arr[numItems/2]->getPriority() && numItems >=1){
//                arr[numItems] = arr[numItems/2];
//                arr[numItems/2] = pj;
//                numItems/=2;
//            }
//            numItems++;
        }
    }
}

void Heap::dequeue() {
    if (numItems == 0){
        return;
    }
    arr[0] ->createHole();
    trickleDown(0);
    return;
}
PrintJob* Heap::highest() {
    if (numItems == 0){
        return nullptr;
    }
    return arr[0];
}
void Heap::print() {
    if (numItems > 0){
        cout << "Priority: " << arr[0]->getPriority() <<
            ", Job Number: " << arr[0]->getJobNumber() <<
            ", Number of Pages: " << arr[0]->getPages() << endl;
    }
}
void Heap::trickleDown(int i) {
    int large;
    int l =2*i + 1;
    int r = 2*i +2;
    if (l < numItems && arr[l]->getPriority() > arr[i]->getPriority()){
        large =l;
    }
    else{
        large = i;
    }
    if (r < numItems&& arr[r]->getPriority() > arr[large]->getPriority()){
        large = r;
    }
    if (large != i){
        PrintJob *temp;
        temp = arr[large];
        arr[large] = arr[i];
        arr[i] = temp;
        trickleDown(large);
    }
}