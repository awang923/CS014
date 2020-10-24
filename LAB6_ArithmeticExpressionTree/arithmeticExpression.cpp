//
// Created by jerrywang on 2020/5/6.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#include "arithmeticExpression.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <cstdlib>
using namespace std;

arithmeticExpression::arithmeticExpression(const string &infix) {
    infixExpression = infix;
    root = nullptr;
}
void arithmeticExpression::buildTree() {
    stack<TreeNode*> nodePtr;
    string element = infix_to_postfix();
    for (unsigned i = 0; i < element.size(); i++){
        if (element.at(i) == '+' || element.at(i) == '-' || element.at(i) == '*' || element.at(i) == '/'){
            TreeNode* child1;
            TreeNode* child2;
            child1 = nodePtr.top();
            nodePtr.pop();
            child2 = nodePtr.top();
            nodePtr.pop();
            nodePtr.push(new TreeNode(element.at(i), 97+i));
            nodePtr.top()->left = child2;
            nodePtr.top()->right = child1;
        }
        else{
            nodePtr.push(new TreeNode(element.at(i), 97+i));
        }
    }
    root = nodePtr.top();
}

//inorder
void arithmeticExpression::infix(TreeNode *curr) {
    if (curr->left != nullptr && curr->right != nullptr){
        cout << "(";
        infix(curr->left);
        cout << curr->data;
        infix(curr->right);
        cout << ")";
    }
    else{
        cout << curr->data;
    }
}
void arithmeticExpression::infix() {
    infix(root);
}
//preorder
void arithmeticExpression::prefix(TreeNode *curr) {
    if (curr->left!=nullptr && curr->right != nullptr){
        cout << curr->data;
        prefix(curr->left);
        prefix(curr->right);
    }
    else{
        cout << curr->data;
    }
}
void arithmeticExpression::prefix() {
    prefix(root);
}
//postorder
void arithmeticExpression::postfix(TreeNode *curr) {
    if (curr->left!= nullptr && curr->right != nullptr){
//        cout << curr->data;
        postfix(curr->left);
        postfix(curr->right);
        cout << curr->data;
    }
    else{
        cout << curr->data;
    }
}
void arithmeticExpression::postfix() {
    postfix(root);
}


int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
void arithmeticExpression::visualizeTree(ofstream & outFS, TreeNode *node) {
    if (node != nullptr) {
        outFS << node->key << "[ label = " << "\"" << node->data << "\"" << " ]" <<endl;
        if (node->left != nullptr) {
            outFS  << node->key <<  "->" << node->left->key << "[ label = "
            << "\"" << node->left->data << "\"" << " ]" << endl;
            visualizeTree(outFS, node->left);
        }

        if (node->right != nullptr) {
            outFS  << node->key << " -> " << node->right->key << "[ label =  "
            << "\"" << node->right->data << "\"" << " ]" << endl;
            visualizeTree(outFS, node->right);
        }

        outFS << endl;
    }
}