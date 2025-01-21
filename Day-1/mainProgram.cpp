#include "functionToSort.cpp"

int main(){
    cout<<"Welcome to the world of programming\n";
    cout<<"The program is dedicated to sort the array containing 0 and 1 only\n";
    int size;
    cout<<"Please enter the size of the array = ";
    cin>>size;
    int arr[size];
    cout<<"Please enter the elements of the array as per given below:-\n";
    for(int i=0;i<size;i++){
        cout<<"Please enter the "<<i+1<<" element = ";
        cin>>arr[i];
    }
    cout<<"Your array looks as {";
    for(int i=0;i<size;i++){
        if(i<size-1)cout<<arr[i]<<",";
        else cout<<arr[i]<<"}";
    }
    
    worstSort(arr,size);
    cout<<"\nYour array after worst efficient sorting looks as {";
    // effSort(arr,size);
    // cout<<"\nYour array after most efficient sorting looks as {";
    for(int i=0;i<size;i++){
        if(i<size-1)cout<<arr[i]<<",";
        else cout<<arr[i]<<"}";
    }
    
}
