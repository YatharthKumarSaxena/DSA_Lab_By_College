#include <iostream>
#include <fstream>
using namespace std;

int main(){
    cout<<"Welcome to the world of Programming\n";
    ifstream in;
    string line;
    in.open("extraConcept.txt");
    while(getline(in,line)){
        cout<<line<<endl;
    }
    in.close();
    return 0;
}