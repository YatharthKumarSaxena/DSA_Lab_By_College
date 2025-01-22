#include "class.cpp"

template <class Type>
void LinkedList<Type>::display(){
    if(Head == NULL){
        cout<<"Your List is empty\n";
        return;
    }
    ListNode<Type>* temp = Head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template <class Type>
int LinkedList<Type>::searchNode(Type val){
    int count = 1;
    ListNode<Type>* temp = Head;
    while(temp){
        if(temp->val == val){
            return count;
        }
        temp = temp->next;
        count++;
    }
    return -1;
}

template <class Type>
int LinkedList<Type>::size(){
    int count = 0;
    ListNode<Type>* temp = Head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

template <class Type>
void LinkedList<Type>::insertAtHead(Type val){
    ListNode<Type>* newNode = new ListNode<Type>(val);
    if(Head == NULL){
        Head = newNode;
        return;
    }
    newNode->next = Head;
    Head = newNode;
    return;
}

template <class Type>
void LinkedList<Type>::insertAtEnd(Type val){
    ListNode<Type>* newNode = new ListNode<Type>(val);
    if(Head == NULL){
        this->insertAtHead(val);
        return;
    }
    ListNode<Type>* temp = Head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

template <class Type>
void LinkedList<Type>::insertAtNthNode(Type val,int loc){
    if(loc < 1 || loc > this->size()+1){
        cout<<"Node cannot be inserted at "<<loc<<"th position\n";
        return;
    }
    else if(loc == 1){
        this->insertAtHead(val);
        return;
    }
    else if(loc == this->size()+1){
        this->insertAtEnd(val);
        return;
    }
    else{
        ListNode<Type>* temp = new ListNode<Type>(val);
        ListNode<Type>* save = Head;
        ListNode<Type>* ptr = Head->next;
        for(int i=1;i<loc-1;i++){
            save = ptr;
            ptr = ptr->next;
        }
        save->next = temp;
        temp->next = ptr;
    }
}

template <class Type>
void LinkedList<Type>::insertAfterNthNode(Type val,int loc){
    insertAtNthNode(val,loc+1);
    return;
}

template <class Type>
void LinkedList<Type>::insertBeforeNthNode(Type val,int loc){
    insertAtNthNode(val,loc);
    return;
}

template <class Type>
void LinkedList<Type>::insertAfterValue(Type val,Type insertedVal){
    int loc = this->searchNode(val);
    if(loc == -1){
        cout<<"No node of value "<<val<<" exists in the Linked List\n";
        return;
    }
    this->insertAtNthNode(insertedVal,loc+1);
    return;
}

template <class Type>
void LinkedList<Type>::insertBeforeValue(Type val,Type insertedVal){
    int loc = this->searchNode(val);
    if(loc == -1){
        cout<<"No node of value "<<val<<" exists in the Linked List\n";
        return;
    }
    this->insertAtNthNode(insertedVal,loc-1);
    return;
}

template <class Type>
Type LinkedList<Type>::deleteAtHead(){
    if(Head == NULL){
        cout<<"Underflow Error\n";
        return Type();
    }
    Type val = Head->val;
    Head = Head->next;
    return val;
}

template <class Type>
Type LinkedList<Type>::deleteAtEnd(){
    if(Head == NULL){
        cout<<"Underflow Error\n";
        return Type();
    }
    if(Head->next == NULL){
        return this->deleteAtHead();
    }
    ListNode<Type>* save = Head;
    ListNode<Type>* ptr = Head->next;
    while(ptr->next){
        save = ptr;
        ptr = ptr->next;
    }
    save->next = NULL;
    return ptr->val;
}

template <class Type>
Type LinkedList<Type>::deleteNthNode(int loc){
    if(loc < 1 || loc > this->size()){
        cout<<"Underflow Error\n";
        return Type();
    }
    else if(loc == 1){
        return this->deleteAtHead();
    }
    else if(loc == this->size()){
        return this->deleteAtEnd();
    }
    ListNode<Type>* save = Head;
    ListNode<Type>* ptr = Head->next;
    for(int i=1;i<loc-1;i++){
        save = ptr;
        ptr = ptr->next;
    }
    save->next = ptr->next;
    return ptr->val;
}

template <class Type>
Type LinkedList<Type>::deleteAfterNthNode(int loc){
    return deleteNthNode(loc+1);
}

template <class Type>
Type LinkedList<Type>::deleteBeforeNthNode(int loc){
    return deleteNthNode(loc-1);
}

template <class Type>
Type LinkedList<Type>::deleteValue(Type val){
    int loc = this->searchNode(val);
    if(loc == -1){
        cout<<"Deletion not possible as no Node of value "<<val<<" exists\n";
        return Type();
    }
    return this->deleteNthNode(loc);
}

template <class Type>
Type LinkedList<Type>::deleteAfterValue(Type val){
    int loc = this->searchNode(val);
    if(loc == -1){
        cout<<"Deletion not possible as no Node of value "<<val<<" exists\n";
        return Type();
    }
    return this->deleteNthNode(loc+1);
}

template <class Type>
Type LinkedList<Type>::deleteBeforeValue(Type val){
    int loc = this->searchNode(val);
    if(loc == -1){
        cout<<"Deletion not possible as no Node of value "<<val<<" exists\n";
        return Type();
    }
    return this->deleteNthNode(loc-1);
}
