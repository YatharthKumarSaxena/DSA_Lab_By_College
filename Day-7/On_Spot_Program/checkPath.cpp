#include <iostream>
#include <fstream>
using namespace std;

class Graph{
    int** arr;
    int rows,columns;
public:
    Graph(){
        rows = 0;
        columns = 0;
        arr = NULL;
    }
    Graph(int rows,int columns){
        this->rows = rows;
        this->columns = columns;
        arr = new int*[rows];
        for(int i=0;i<rows;i++){
            arr[i] = new int[columns];
            for(int j=0;j<columns;j++){
                arr[i][j] = 0;
            }
        }
    }
    void displayGraph();
    void makeGraph();
    bool checkPath(int src,int des);
};

void Graph::makeGraph(){
    ifstream in;
    in.open("graph.txt");
    string line;
    while(getline(in,line)){
        rows++;
    }
    in.close();
    in.open("graph.txt");
    char c = in.get();
    int totalElements = 0;
    while(!in.eof()){
        in>>c;
        totalElements++;
    }
    columns = totalElements/rows;
    arr = new int*[rows];
    for(int i=0;i<rows;i++){
        arr[i] = new int[columns];
        for(int j=0;j<columns;j++){
            arr[i][j] = 0;
        }
    }
    in.close();
    in.open("graph.txt");
    int n = 0;
    c = in.get();
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            arr[i][j] = c-48;
            in>>c;
        }
    }
    in.close();
    cout<<"Graph is created Successfully\n";
}

void Graph::displayGraph(){
    cout<<"Your Graph in Adjacency Matrix form is displayed below:-\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool Graph::checkPath(int src,int des){
    if(src<0 || src>=rows || des<0 || des>=columns)return false;
    else if(arr[src][des] == 1)return true;
    return (checkPath(src+1,des)||checkPath(src-1,des)||checkPath(src,des-1)||checkPath(src,des+1));
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    cout<<"This Program is dedicated to explore how to read Adjacency Matrix text file and convert into Graph\n";
    cout<<"Program is dedicated to find that whether a path exists between two vertices\n";
    Graph G;
    G.makeGraph();
    G.displayGraph();
    while(true){
        cout<<"\nTo check path Exist or Not\n";
        cout<<"Press 1 to check\n";
        cout<<"Press 0 to Exit main program\n";
        int choice;
        cout<<"Please enter your choice:- ";
        cin>>choice;
        if(choice == 1){
            int src,des;
            cout<<"Please enter the Source Node:- ";
            cin>>src;
            cout<<"Please enter the destination Node:- ";
            cin>>des;
            bool path = G.checkPath(src,des);
            if(path)cout<<"Path Exists\n";
            else cout<<"Path does not exist\n";
        }
        else if(choice == 0){
            cout<<"Exiting main program\n";
            exit(0);
        }
        else{
            cout<<"Invalid Choice , please try again\n";
        }
    }
    return 0;
}