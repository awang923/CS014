//
// Created by jerrywang on 2020/5/7.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#include "BSTree.h"
#include <iostream>
#include <string>
using namespace std;

BSTree::BSTree() {
    root = nullptr;
}
void BSTree::insert(const string &newString) {
    Node *newNode = new Node(newString);
    Node* curr = root;
    if (root == nullptr){
        root = newNode;
        newNode->left = nullptr;
        newNode->right = nullptr;
        root->increaseCount();
    }
    else{
//        if (newNode->data != curr->data){
        while(curr!= nullptr){
            if (newNode->data == curr->data){
                curr->increaseCount();
                return;
            }
            if(newNode->data < curr->data){
                if (curr->left == nullptr){
                    curr->left = newNode;
                    newNode->increaseCount();
                    curr = nullptr;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if (newNode->data > curr->data){
                    if (curr->right == nullptr){
                        curr->right = newNode;
                        newNode->increaseCount();
                        curr = nullptr;
                    }
                    else{
                        curr = curr->right;
                    }
                }
            }
        }
    }
}
bool BSTree::search(Node *curr, const string& key) const {
//    bool trash = true;
//    Node* temp = curr;
    if (curr == nullptr) {
        return false;
    }
    if (key == curr->data) {
        return true;
    }
    if (curr->left == nullptr && curr->right == nullptr && key!=curr->data){
        return false;
    }
    else {
        if (key < curr->data) {
            return search(curr->left, key);
        }
        else {
            return search(curr->right, key);
        }
    }
//    return false;
}
bool BSTree::search(const string &key) const {
    bool isFound = search(root, key);
    return isFound;
}
string BSTree::largest() const {
    Node* largest = root;
    if (root == nullptr){
        return "";
    }
    else{
        while (largest->right != nullptr){
            largest = largest->right;
        }
    }
    return largest->data;
}
string BSTree::smallest() const {
    Node* smallest = root;
    if (root == nullptr){
        return "";
    }
    else{
        while (smallest->left != nullptr){
            smallest = smallest->left;
        }
    }
    return smallest->data;
}
int BSTree::height(const string &key) const {
    Node* curr = root;
    if (curr == nullptr){
        return -1;
    }
    while(curr!=nullptr && curr->data!= key){
        if(key < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }

    return height(curr);
}
int BSTree::height(Node *curr) const{
    if (curr == nullptr){
        return -1;
    }
//    if (curr->left == nullptr && curr->right == nullptr){
//        return 0;
//    }
    int lh = height(curr->left);
    int rh = height(curr->right);
    if(lh > rh){
        return 1 + lh;
    }
    else{
        return 1 + rh;
    }
}
void BSTree::preOrder(Node *curr) const{
    //root->left->right
    if (curr == nullptr){
        return;
    }
    cout << curr->data << "(" << curr->count << "), ";
    preOrder(curr->left);
    preOrder(curr->right);
}
void BSTree::preOrder() const {
    preOrder(root);
}
void BSTree::postOrder(Node* curr) const {
    //left->right->root
    if (curr == nullptr){
        return;
    }
    postOrder(curr->left);
    postOrder(curr->right);
    cout << curr->data << "(" << curr->count << "), ";
}
void BSTree::postOrder() const {
    postOrder(root);
}
void BSTree::inOrder(Node * curr) const{
    //left->root->right
    if (curr == nullptr){
        return;
    }
    inOrder(curr->left);
    cout << curr->data << "(" << curr->count << "), ";
    inOrder(curr->right);
}
void BSTree::inOrder() const {
    inOrder(root);
}
//help from previous student
Node* BSTree::remove(Node* curr, const string& key) {
    if (root == nullptr){
        return nullptr;
    }
    if(key < curr->data){
        curr->left = remove(curr->left, key);
    }
    else if (key > curr->data){
        curr->right = remove(curr->right, key);
    }
    else{
        if (curr->count > 1){
            curr->decreaseCount();
            return curr;
        }
//        case1 remove leaf
        if(curr->left == nullptr && curr->right == nullptr && curr == root){
            delete curr;
            root = nullptr;
        }
        else if(curr->left == nullptr && curr->right == nullptr){
            delete curr;
            return nullptr;
        }
//        case2 remove one child
        else if(curr->right == nullptr){
            curr->data = curr->left->data;
            if (curr == root){
                root = curr->left;
                delete curr;
            }
            else{
                curr->left = curr->left->left;
//                curr->right = curr->right->right;
                delete curr->left;
            }
        }
        else if(curr->left == nullptr){
            Node* succ = min(curr->right);
            curr->data = succ->data;
            curr->count = succ->count;
            succ->count = 0;
            curr->right = remove(curr->right,succ->data);
            return curr;
        }
        else if(curr->right == nullptr){
            Node* succ = min(curr->left);
            curr->data = succ->data;
            curr->count = succ->count;
            succ->count = 0;
            curr->left = remove(curr->left,succ->data);
            return curr;
        }
//        case3 remove two children
        else{
            Node* nxt = max(curr->left);
            curr->data = nxt->data;
            curr->count = nxt->count;
            nxt->count = 1;
            curr->left = remove(curr->left, nxt->data);
        }
    }
    return curr;
}
Node* BSTree::min(Node* x){
    Node* temp = x;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp;
}

Node* BSTree::max(Node* y){
    Node* temp = y;
    while(temp->right != nullptr){
        temp = temp->right;
    }
    return temp;
}
void BSTree::remove(const string &key) {
    if (!search(key)){
        return;
    }
    else{
        remove(root, key);
    }
}