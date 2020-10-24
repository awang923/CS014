//
// Created by jerrywang on 2020/4/21.
// Copyright (c) 2020 anniewang. All rights reserved.
//

#include "WordLadder.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stack>
#include <queue>
using namespace std;
WordLadder::WordLadder(const string & fileName) {
    ifstream inFS;
    string word;
    inFS.open(fileName);
    if (!inFS.is_open()){
        cout << ("Error opening file.") << endl;
        return;
    }
    while (inFS >> word){
        if(word.length() == 5){
            dict.push_back(word);
        }
        else{
            cout << "Dictionary only stores words with length of 5" << endl;
            return;
        }
    }
    inFS.close();
}
bool WordLadder::check(const string& lhs, const string& rhs) {
    int count = 0;
    for (unsigned i = 0; i < lhs.length(); ++i){
        if (lhs.at(i)!=rhs.at(i)){
            count++;
        }
    }
    if (count <= 1){
        return true;
    }
    return false;
}
void WordLadder::stackRev(stack<string>& st, ofstream& file) {
    if(st.empty()){
        return;
    }
    stack<string>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }



    while(temp.size()>0){

        string word = temp.top();
        temp.pop();
        file << word << " ";
    }
}

// COLLAB WITH JONAS SEGUNDO
void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    ofstream outFS;
    stack<string>firstWord;

    firstWord.push(start);
    queue<stack<string> >words;
    stack<string>frontStack;
    words.push(firstWord);
    string last;

    outFS.open(outputFile);
    while (!outFS.is_open()){
        cout << "Error opening output file" << endl;
        return;
    }
    for(list<string>::iterator i = dict.begin(); i != dict.end(); i++){
        last = *i;
        if(start == last){
            break;
        }
    }
    if(last != start){
        outFS << "No Word Ladder Found" << endl;
        return;
    }
    for(list<string>::iterator i = dict.begin(); i != dict.end(); i++){
        last = *i;
        if(last == end){
            break;
        }
    }
    if(last != end){
        outFS << "No Word Ladder Found" << endl;
        return;
    }
    if(start == end){
        outFS << start << endl;
        return;
    }
    while(!words.empty()){
        frontStack = words.front();
        string topWord = frontStack.top();
        for (list<string>::iterator i = dict.begin(); i!= dict.end();i++){
            if (check(topWord,*i)) {
                stack<string> newStack = words.front();
                newStack.push(*i);
                if (*i == end) {
                    stack<string> temp = newStack;
                    stackRev(temp, outFS);
                    outFS << endl;
                    return;
                }
                words.push(newStack);
                i = dict.erase(i);
                i = dict.begin();
            }
        }
        words.pop();
    }
    outFS << "No Word Ladder Found." << endl;
    outFS.close();

}