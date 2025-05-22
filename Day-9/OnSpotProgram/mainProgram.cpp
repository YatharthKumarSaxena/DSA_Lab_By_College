#include "dsu.cpp"
#include <fstream>

class Edge{
public:
    char src;
    char des;
    int weight;
    Edge(){

    }
    Edge(char src,char des,int weight){
        this->src = src;
        this->des = des;
        this->weight = weight;
    }
};

void sortEdges(Edge* edge,int size){
    for(int i=0;i<size-1;i++){
        bool flag = false;
        for(int j=0;j<size-i-1;j++){
            if(edge[j].weight>edge[j+1].weight){
                Edge temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
                flag = true;
            }
        }
        if(!flag)break;
    }
}

int kruskal(Edge* edge,int edges,int vertices){
    if(vertices <= 1)return 0;
    if(edges == 1)return edge[0].weight;
    int cost = 0;
    DSU dsu(vertices);
    sortEdges(edge,edges);
    dsu.unionGroup(edge[0].src-65,edge[0].des-65);
    cost += edge[0].weight;
    int size = vertices - 1;
    int i = 1;
    int j = 1;
    while(j<edges && i<size){
        int a = edge[j].src-65;
        int b = edge[j].des-65;
        int w = edge[j].weight;
        if(dsu.findParent(a)==dsu.findParent(b)){
            j++;
        }
        else{
            dsu.unionGroup(a,b);
            cost += w;
            i++;
            j++;
        }
    }
    return cost;
}

int main(){
    cout<<"Welcome to the World of Programming\n";
    ifstream in;
    in.open("read.txt");
    char c;
    in>>c;
    int vertices=0,edges=0;
    while(c!='{'){
        in>>c;
    }
    while(c!='}'){
        if(65<=c && c<=90){
            vertices++;
        }
        in>>c;
    }
    while(c!='{'){
        in>>c;
    }
    while(c!='}'){
        if(c=='(')edges++;
        in>>c;
    }
    in.close();
    in.open("read.txt");
    in>>c;
    Edge* edge = new Edge[edges];
    char* vertex = new char[vertices];
    in>>c;
    while(c!='{')in>>c;
    int k = 0;
    while(c!='}'){
        if(c>=65 && c<=90)vertex[k++] = c;
        in>>c;
    }
    while(c!='{')in>>c;
    int i = 0;
    while(c!='}'){
        char src,des;
        int weight;
        bool flag = false;
        while(c!=')'){
            if(65<=c && c<=90){
                if(!flag){
                    src = c;
                    flag = true;
                }
                else{
                    des = c;
                    flag = false;
                }
            }
            if(48<=c && c<=57){
                weight = c-48;
            }
            in>>c;
        }
        Edge e(src,des,weight);
        edge[i++] = e;
        in>>c;
    }
    cout<<"\nTotal Number of Edges in Your Graph: "<<edges<<"\nSet of Edges in your Graph is displayed below:- \n";
    for(int j=0;j<edges;j++){
        cout<<endl;
        cout<<j+1<<"th Edge:- \n";
        cout<<"Source:- "<<edge[j].src<<endl;
        cout<<"Destination:- "<<edge[j].des<<endl;
        cout<<"Weight:- "<<edge[j].weight<<endl;
    }
    cout<<"\nTotal Number of Vertices in Your Graph: "<<vertices<<"\nSet of Vertices in your Graph is displayed below:- \n";
    for(int j=0;j<vertices;j++){
        cout<<endl;
        cout<<j+1<<"th Vertex is "<<vertex[j];
    }
    int mstCost = kruskal(edge, edges, vertices);
    cout << "\n\nMinimum Cost of Spanning Tree using Kruskal's Algorithm is: " << mstCost << endl;
    return 0;
}