#include <iostream>
#include <fstream>
using namespace std;
int main(){
    cout<<"Copying your Entered Array into A file\n";
    string fileName;
    cout<<"Please enter the name of the file in which you want to enter your Array Elements:- ";
    cin>>fileName;
    ofstream out;
    out.open(fileName+".txt"); // Creates a New File Based On User Demand
    cout<<"Please enter the number of Elements into Your Array:- ";
    out<<"Your Array Looks as given below :-"<<endl<<"{";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Please enter your "<<i+1<<" elements: ";
        int a;
        cin>>a;
        if(i<n-1)out<<a<<",";
        else out<<a<<"}";
    }
    out.close();
    return 0;
}