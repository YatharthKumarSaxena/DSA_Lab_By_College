#include "Moore's_Voting_Algorithm.cpp"

int main(){
    cout<<"Please enter the size of the array = ";
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cout<<"Please enter the "<<i+1<<" element = ";
        cin>>arr[i];
    }
    cout<<"\nYour Array looks like :- {";
    for(int i=0;i<n;i++){
        if(i<n-1)cout<<arr[i]<<",";
        else cout<<arr[i]<<"}";
    }
    cout<<endl;
    findMajorityElement(arr,n);
}