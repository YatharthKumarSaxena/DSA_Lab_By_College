#include <iostream>
#include <fstream> // For File Handling

using namespace std;

int main(){
    cout<<"Welcome to the World of Programming\n";
    ofstream out; // Ofstream object for Wrting into the File
    // Opening a file or Create a file if not created
    out.open("input.txt");
    // Way to Write a file
    out<<"Hello I am writing into the file named as input.txt";
    out.close(); // For Releasing the Resource
    return 0;
}