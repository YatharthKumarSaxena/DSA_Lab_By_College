#include <iostream>
using namespace std;

class Graph{
    int** arr;
    int v;
public:
    Graph(){
        v = 0;
        arr = NULL;
    }
    void makeGraph(bool dir);
    void reverseGraph(bool dir);
    void displayGraph();
    ~Graph() {
        for(int i = 0; i < v; i++)
            delete[] arr[i];
        delete[] arr;
    }
};

void Graph::makeGraph(bool dir){
    cout<<"\nPlease enter the number of vertices in your Graph:- ";
    cin>>v;
    arr = new int*[v];
    for(int i=0;i<v;i++){
        arr[i] = new int[v];
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }
    cout<<"Please enter the number of Edges:- ";
    int e;
    cin>>e;
    while(e--){
        int src,des;
        cout<<"Please enter the source:- ";
        cin>>src;
        cout<<"Please enter the destination:- ";
        cin>>des;
        arr[src][des] = 1;
        if(!dir)arr[des][src] = 1;
    }
    cout<<"Your Graph created Successfully\n";
}

void Graph::reverseGraph(bool dir){
    if(!dir){
        cout<<"Graph is Undirected so Reverse is not Possible\n";
        return;
    }
    for(int i=0;i<v;i++){
        for(int j=i+1;j<v;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    cout<<"Now Graph is Reversed Successfully\n";
    return;
}

void Graph::displayGraph(){
    cout<<"Your Graph in Adjacency Matrix form is displayed below:-\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    cout<<"This Program is dedicated to explore implementation of Adjacency Matrix and how to reverse the edges\n";
    cout<<"Do you want to make Graph Directed or Undirected\n";
    cout<<"For Directed press 1 and for undirected press 0:- ";
    bool flag;
    cin>>flag;
    Graph G;
    G.makeGraph(flag);
    G.displayGraph();
    G.reverseGraph(flag);
    cout<<"After reverse, ";
    G.displayGraph();
    return 0;
}