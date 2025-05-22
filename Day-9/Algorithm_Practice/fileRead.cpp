#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream in;
    in.open("practice.txt");
    string line;
    while(getline(in,line)){
        cout<<line<<endl;
        int n = line.size();
        cout<<n<<endl;
    }
    return 0;
}