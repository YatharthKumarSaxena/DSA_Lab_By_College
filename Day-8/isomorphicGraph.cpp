#include <iostream>
#include <fstream>
using namespace std;

class Graph{
    int **adj;
    int vertices;
public:
    Graph(int vertices){
        this->vertices = vertices;
        adj = new int*[vertices];
        for(int i=0;i<vertices;i++){
            adj[i] = new int[vertices];
        }
    }
    void addEdge(int src,int des,bool dir);
    int getTotalVertices();
    int getTotalEdges();
};

void Graph:: addEdge(int src,int des,bool dir){
    if(src>=vertices || src<0 || des>=vertices || des<0){
        cout<<"Invalid Vertices Entered by You\n";
        return;
    }
    adj[src][des] = 1;
    if(!dir) adj[des][src] = 1;
    return;
}

int Graph::getTotalVertices(){
    return this->vertices;
}

int Graph::getTotalEdges(){
    int count = 0;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            if(adj[i][j])count++;
        }
    }
    return count;
}

Graph makeGraph(){
    
}

bool checkIsomorphicGraph(Graph G1,Graph G2){

}

int main(){
    cout<<"\nWelcome to the World of Programming\n";
    cout<<"This Program is Dedicated to explore that two graphs are isomorphic or not\n";
    cout<<"Given that Graph is undirected graph but we need to extract it from the text file and make it\n";
    cout<<"Graph is given in form of set of Vertices and Edges\n";

    return 0;
}
