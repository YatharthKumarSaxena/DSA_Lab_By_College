#include <iostream>
using namespace std;

// Most Efficient Approach to Sort the Arrays of 0 and 1 in O(n) Time Complexity
void effSort(int arr[],int size){
    int firstPointer = 0;
    int secondPointer = size-1;
    while(firstPointer<secondPointer){
        if(arr[firstPointer] == 1 && arr[secondPointer] == 0){
            arr[firstPointer] = 0;
            arr[secondPointer] = 1;
            firstPointer++;
            secondPointer--;
        }
        else if(arr[secondPointer] == 1){
            secondPointer--;
        }
        else firstPointer++;
    }
}

// Worst Algorithm to sort the array in O(n^2) Complexity
void worstSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        bool flag = true;
        for(int j=0;j<size-1-i;j++){
            if(arr[j+1]==0 && arr[j]==1){
                arr[j+1] = 1;
                arr[j] = 0;
                flag = false;
            }
        }
        if(flag)break;
    }
}
