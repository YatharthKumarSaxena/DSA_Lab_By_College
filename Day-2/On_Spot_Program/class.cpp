#include <iostream>
using namespace std;

template <class Type>
class ListNode{
public:
    // Data Members
    Type val;
    ListNode<Type>* next;
    // Parameterized Constructors
    ListNode(Type val){
        this->val = val;
        this->next = NULL;
    }
};

template <class Type>
class LinkedList{
    // Data Members
    ListNode<Type>* Head;
public:
    // Default Constructor
    LinkedList(){
        this->Head = NULL;
    }
    // Member Functions
    void insertAtHead(Type val);
    void insertAtEnd(Type val);
    void insertAtNthNode(Type val,int loc);
    void insertBeforeValue(Type val,Type insertedValue);
    void insertAfterValue(Type val,Type insertedValue);
    void insertAfterNthNode(Type val,int loc);
    void insertBeforeNthNode(Type val,int loc);
    Type deleteAtHead();
    Type deleteAtEnd();
    Type deleteNthNode(int loc);
    Type deleteAfterNthNode(int loc);
    Type deleteBeforeNthNode(int loc);
    Type deleteValue(Type val);
    Type deleteAfterValue(Type val);
    Type deleteBeforeValue(Type val);
    void display();
    int size();
    int searchNode(Type val);
};