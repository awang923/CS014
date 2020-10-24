//
//  main.cpp
//  LAB9_Sorting
//
//  Created by jerrywang on 2020/5/25.
//  Copyright © 2020 anniewang. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;

//given
const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000;
const int NUMBERS_SIZE = 50000;
int genRandInt(int low, int high) {
    return low + rand() % (high - low + 1);
}
void fillArrays(int arr1[], int arr2[],int arr3[]){
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}

int midPartition(int numbers[], int i, int k){
    int midPt = i+(k-i)/2;
    int midVal = numbers[midPt];
    bool done = false;
    while(!done){
        while(numbers[i] < midVal){
            i++;
        }
        while(numbers[k] > midVal){
            k--;
        }
        if(i >= k){
            done = true;
        }
        else{
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            i++;
            k--;
        }
    }
    return k;
}
void Quicksort_midpoint(int numbers[], int i, int k){
    int mid = midPartition(numbers, i, k);
    if (k <= i){
        return;
    }
    else{
        Quicksort_midpoint(numbers, i, mid);
        Quicksort_midpoint(numbers, mid+1, k);
    }
}
int medPartition(int numbers[], int i, int k){
    int midPt = i+(k-i)/2;
    int midVal = numbers[midPt];
    int medVal = 0;
    if (midVal >= numbers[i] && midVal <= numbers[k]){
        medVal = midVal;
    }
    else if (midVal >= numbers[k] && midVal <= numbers[i]){
        medVal = midVal;
    }
    else if (numbers[i] >= midVal && numbers[i] <= numbers[k]){
        medVal = numbers[i];
    }
    else if (numbers[i] <= midVal && numbers[i] >= numbers[k]) {
        medVal = numbers[i];
    }
    else if (numbers[k] >= midVal && numbers[k] <= numbers[i]){
        medVal = numbers[k];
    }
    else{
        medVal = numbers[k];
    }
    bool done = false;
    while(!done){
        while(numbers[i] < medVal){
            i++;
        }
        while(numbers[k] > medVal){
            k--;
        }
        if(i >= k){
            done = true;
        }
        else{
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
            i++;
            k--;
        }
    }
    return k;
}
void Quicksort_medianOfThree(int numbers[], int i, int k){
    int med = medPartition(numbers, i, k);
    if (k <= i){
        return;
    }
    else{
        Quicksort_medianOfThree(numbers, i, med);
        Quicksort_medianOfThree(numbers, med+1, k);
    }
}
void InsertionSort(int numbers[], int numbersSize){
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 1; i < numbersSize; ++i){
        j = i;
        while (j > 0 && numbers[j] < numbers[j-1]){
            temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            j--;
        }
    }
}
int main(int argc, const char * argv[]) {
    srand(time(NULL));
    int arr1[NUMBERS_SIZE];
    int arr2[NUMBERS_SIZE];
    int arr3[NUMBERS_SIZE];
    fillArrays(arr1, arr2, arr3);
    int elapsedTime = 0;
    clock_t Start;
    clock_t End;
    cout << "Midpoint Sort" << endl;
    cout << "OG array" << endl;
    for (int i = 0; i < 10; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    Start = clock();
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE-1);
    for (int i = 0; i < 10; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Elapsed Time: " << elapsedTime << endl << endl;

    cout << "Median Sort" << endl;
    cout << "OG array" << endl;
    for (int i = 0; i < 10; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    Start = clock();
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE-1);
    for (int i = 0; i < 10; i++){
        cout << arr2[i] << " ";
    }
    cout << endl;
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Elapsed Time: " << elapsedTime << endl << endl;

    cout << "Insertion Sort" << endl;
    cout << "OG array" << endl;
    for (int i = 0; i < 10; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;
    Start = clock();
    InsertionSort(arr3, NUMBERS_SIZE-1);
    for (int i = 0; i < 10; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS;
    cout << "Elapsed Time: " << elapsedTime << endl << endl;
    return 0;
}