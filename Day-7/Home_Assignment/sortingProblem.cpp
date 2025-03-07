#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int main(){
    cout<<"This file sorts the number in ascending order\n";
    ifstream in;
    in.open("number.txt");
    char c;
    in>>c;
    vector<int>v;
    cout<<"Content of the file is given below:-\n";
    while(!in.eof()){
        cout<<c;
        v.push_back(c);
        in>>c;
    }
    in.close();
    cout<<"\nContent of the file After Sorting is given below:-\n";
    ofstream out;
    out.open("number.txt");
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        out<<v[i]-48<<" ";
        cout<<v[i]-48<<" ";
    }
    out.close();
    return 0;
}