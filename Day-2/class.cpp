#include <iostream>
#include <vector>
using namespace std;

// ListNode Class
template <class Type>
class ListNode{
public:
    Type val; // Stores the Data
    int next; // Stores the Next Address
    ListNode(Type val){
        this->val = val;
        this->next = -1;
    }
};

template <class Type>
// Linked List Class Without Pointers
class LinkedList{
    int headIdx;
    vector<ListNode<Type>>nodes;
public:
    LinkedList(){
        headIdx = -1;
    }
    void insertAtHead(Type val);
    void insertAtTail(Type val);
    Type deleteAtHead();
    Type deleteAtTail();
    int size();
    void display();
    void insertAfterNthNode(Type val,int n);
    void insertBeforeNthNode(Type val,int n);
    void reverse();
    Type deleteNthNode(int n);
};