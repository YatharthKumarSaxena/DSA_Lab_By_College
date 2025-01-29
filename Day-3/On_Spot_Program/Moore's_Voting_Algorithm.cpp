#include <iostream>
using namespace std;

// Moore's Voting Algorithm
void findMajorityElement(int arr[],int size){
    if(size<=0){
        cout<<"Array is of Zero Size or Invalid Array Size\n";
        return;
    }
    int count = 1;
    int ele = arr[0];
    for(int i=1;i<size;i++){
        if(ele == arr[i])count++;
        else{
            count--;
            if(count == 0){
                count = 1;
                ele = arr[i];
            }
        }
    }
    count = 0;
    for(int i=0;i<size;i++){
        if(arr[i] == ele)count++;
    }
    if(count>= (size/2)+1)cout<<"Majority Element having value "<<ele<<" exists in Array\n";
    else cout<<"None of the element in array is majority element\n";
}