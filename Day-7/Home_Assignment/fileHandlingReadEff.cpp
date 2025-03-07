#include <iostream>
#include <fstream>
using namespace std;

int main(){
    cout<<"Welcome to the World of Programming\n";
    // Reading in Such a way that Tab Space and Whitespace are not ignored
    ifstream in;    // Creation of Instream Object
    // Note:- If File Does not Exist then IfStream Object Fails in Opening that File
    in.open("input.txt");
    char c;
    c = in.get();
    while(!in.eof()){ // Checking End Of File has Come or not
        cout<<c;
        c = in.get(); // Move To Next Character
    }
    in.close();
    return 0;
}