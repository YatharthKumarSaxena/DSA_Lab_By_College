#include <iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
    ListNode* Head;
public:
    LinkedList(){
        this->Head = NULL;
    }
    void insertAtHead(int val);
    void display();
    int deleteAtHead();
    bool empty();
};

void LinkedList::insertAtHead(int val){
    ListNode* newNode = new ListNode(val);
    if(this->Head == NULL){
        Head = newNode;
        return;
    }
    newNode->next = Head;
    Head = newNode;
    return;
}

bool LinkedList::empty(){
    return (Head == NULL);
}

void LinkedList::display(){
    ListNode* temp = Head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

int LinkedList::deleteAtHead(){
    if(!Head){
        cout<<"Linked List is Empty\n";
        cout<<"Underflow Error\n";
        return -1;
    }
    ListNode* temp = Head;
    Head = Head->next;
    int val = temp->val;
    delete temp;  // ✅ Free the node's memory
    return val;
}

class Graph{
    LinkedList* arr;
    int v;
public:
    Graph(){
        arr = NULL;
        v = 0;
    }
    Graph(int v){
        this->v = v;
        arr = new LinkedList[v];
    }
    void addEdge(int src,int des);
    void displayGraph();
    void makeGraph(bool dir);
    void reverseGraph(bool dir);
};

void Graph::reverseGraph(bool dir){
    if(!dir){
        cout<<"Graph is Undirected so Reverse is not Possible\n";
        return;
    }
    LinkedList* ptr;
    ptr = new LinkedList[v];
    for(int i=0;i<v;i++){
        while(!arr[i].empty()){
            int des = arr[i].deleteAtHead();
            ptr[des].insertAtHead(i);
        }
    }
    delete[] arr;
    arr = ptr;
    cout<<"Now Graph is Reversed Successfully\n";
    return;
}

void Graph::displayGraph(){
    cout<<"\nYour Graph in Adjacency List form is displayed below:-\n";
    for(int i=0;i<v;i++){
        cout<<i<<"-> ";
        arr[i].display();
    }
}

void Graph::makeGraph(bool dir){
    cout<<"\nPlease enter the number of vertices in your Graph:- ";
    cin>>v;
    cout<<"Please enter the number of Edges:- ";
    int e;
    cin>>e;
    arr = new LinkedList[v];
    while(e--){
        int src,des;
        cout<<"Please enter the source:- ";
        cin>>src;
        cout<<"Please enter the destination:- ";
        cin>>des;
        this->addEdge(src,des);
        if(!dir)this->addEdge(des,src);
    }
    cout<<"Your Graph created Successfully\n";
    return;
}

void Graph::addEdge(int src,int des){
    arr[src].insertAtHead(des);
    return;
}

int main(){
    cout<<"\nWelcome to the world of programming\n";
    cout<<"This Program is dedicated to explore implementation of Adjacency List and how to reverse the edges\n";
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