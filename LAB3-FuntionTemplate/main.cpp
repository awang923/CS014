//
//  main.cpp
//  LAB3_FunctionTemplate
//
//  Created by jerrywang on 2020/4/14.
//  Copyright © 2020 anniewang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//collaborate with Jonas Segundo

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    T min = vals.at(index);
    unsigned minIndex = index;
    for (unsigned i = index; i < vals.size(); i++){
        if (vals.at(i) < min){
            min = vals.at(i);
            minIndex = i;
        }
    }
    return minIndex;
}
template<typename T>
void selection_sort(vector<T> &vals){
    for (unsigned i = 0; i < vals.size(); i++){
        unsigned minIndex = min_index(vals, i);
        T temp = vals.at(i);
        vals.at(i) = vals.at(minIndex);
        vals.at(minIndex) = temp;
    }
}
template<typename T>
T getElement(vector<T> vals, int index){
    if (index > vals.size()-1 || index <0){
        throw out_of_range("Invalid index");
    }
    return vals.at(index);
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(int argc, const char * argv[]) {
    vector<int> nums;
    int user = 0;
    cout << "insert nums (-1 to stop)" << endl;
    cin >> user;
    while(user != -1){
        nums.push_back(user);
        cout << "insert num" << endl;
        cin >> user;
    }
    selection_sort(nums);
    for ( unsigned i = 0; i < nums.size(); i++){
        cout << nums.at(i) << endl;
    }

    vector<char> chars;
    char stuff;
    cout << "insert char" << endl;
    cin >> stuff;
    while(stuff != 'z'){
        chars.push_back(stuff);
        cout << "insert char" << endl;
        cin >> stuff;
    }
    selection_sort(chars);
    for ( unsigned i = 0; i < chars.size(); i++){
        cout << chars.at(i) << endl;
    }
    int index;
    cout << "Done" << endl;
    cout << "enter a number: " << endl;
    cin >> index;
    while (index != -1){
        try{
            srand(time(0));
            vector<char> vals = createVector();
            char curChar;
            int numOfRuns = 10;
            while(--numOfRuns >= 0){
                cout << "Enter a number: " << endl;
                cin >> index;
                curChar = getElement(vals,index);
                cout << "Element located at " << index << ": is " << curChar << endl;
            }
        }

        catch(out_of_range& excpt){
            cout << "out of range exception occured" << endl;
//        return 1;
        }
    }
//    try{
//        srand(time(0));
//        vector<char> vals = createVector();
//        char curChar;
//        int index;
//        int numOfRuns = 10;
//        while(--numOfRuns >= 0){
//            cout << "Enter a number: " << endl;
//            cin >> index;
//            curChar = getElement(vals,index);
//            cout << "Element located at " << index << ": is " << curChar << endl;
//        }
//    }
//
//    catch(out_of_range& excpt){
//        cout << "out of range exception occured" << endl;
//        return 1;
//    }

    return 0;

}