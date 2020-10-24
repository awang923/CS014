//
//  main.cpp
//  CS14_Challenge1_josephus
//
//  Created by jerrywang on 2020/4/5.
//  Copyright © 2020 anniewang. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
struct PersonNode{
    string name;
    PersonNode *prev;
    PersonNode *next;
    PersonNode(string name) : name(name), prev(0), next(0) {}
};
int main(int argc, const char * argv[]) {
    PersonNode* head = nullptr;
    PersonNode* tail = nullptr;
    ifstream inFS;
    string personName;
    int size = 0;
    int start, skip;
    inFS.open(argv[1]);
    if (!inFS.is_open()){
        cout << "Error opening file dumbass" << endl;
        return 0;
    }
    else{
        while(getline(inFS,personName)){
            PersonNode *temp = new PersonNode(personName);
            if (head == nullptr){
                head = temp;
                tail = temp;
                head->prev = tail;
            }
            else{
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
                temp->next = head;
                head->prev = tail;
            }
            size++;
        }
    }
    cout << "Enter the position to start counting" << endl;
    cin >> start;
    cout << "Enter the amount of people to skip" << endl;
    cin >> skip;
//    if (skip >= size || skip < 2){
//        cout << "Number enter incorrect. Try again."<< endl;
//        cin >> skip;
//    }
    PersonNode* curr;
    if (start == 1){
        curr = head;
    }
    else{
        curr = head;
        for (int i = 1; i < start; i++){
            curr = curr->next;
        }
    }
//    head = curr;
//    head->prev = tail;
    PersonNode *killNode;
    PersonNode *surviveNode;
    while (curr->next!=curr){
        if (skip == 2){
            killNode = curr->next;
            surviveNode = killNode->next;
            curr->next = killNode->next;
            surviveNode->prev = curr;
            delete killNode;
        }
        else{
            killNode = curr;
            for (int i = 1; i < skip; i++){
                killNode = killNode->next;
            }
            surviveNode = killNode->next;
            curr->next = killNode->next;
            surviveNode->prev = curr;
            delete killNode;
        }
        curr = surviveNode;
    }
    cout << curr->name << " survived" << endl;
    return 0;
}