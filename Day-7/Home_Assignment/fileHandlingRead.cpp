#include <iostream>
#include <fstream>
using namespace std;

int main(){
    cout<<"Welcome to the World Of Programming";
    ifstream in;    // To create an Ifstream Object Used for Reading Operations in the file
    // Opening the Files
    in.open("input.txt");
    char c;
    in>>c;
    cout<<endl;
    // Problem With This Approach is that in>>c will ignore here tab space and whitespace
    while(!in.eof()){ // in.eof mean End of File
        cout<<c;
        in>>c; // Means Go to Next Character
    }
    in.close();
    return 0;
}