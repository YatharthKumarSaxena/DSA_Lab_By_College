#include "class.cpp"

// Insertion at Head
template <class Type>
void LinkedList<Type>::insertAtHead(Type val)
{
    ListNode<Type> newNode(val);
    nodes.push_back(newNode);
    int idx = nodes.size() - 1;
    if (this->headIdx == -1)
    {
        this->headIdx = idx;
        return;
    }
    nodes[idx].next = headIdx;
    this->headIdx = idx;
}

// Insertion at End
template <class Type>
void LinkedList<Type>::insertAtTail(Type val)
{
    ListNode<Type> newNode(val);
    nodes.push_back(newNode);
    int address = nodes.size() - 1;
    if (this->headIdx == -1)
    {
        this->headIdx = address;
        return;
    }
    int idx = this->headIdx;
    while (nodes[idx].next != -1)
    {
        idx = nodes[idx].next;
    }
    nodes[idx].next = address;
}

// Count the Size of the LinkedList
template <class Type>
int LinkedList<Type>::size()
{
    int count = 0;
    int idx = this->headIdx;
    while (idx != -1)
    {
        count++;
        idx = nodes[idx].next;
    }
    return count;
}

// Print the Linked List
template <class Type>
void LinkedList<Type>::display()
{
    int idx = this->headIdx;
    while (idx != -1)
    {
        cout << nodes[idx].val << " ";
        idx = nodes[idx].next;
    }
    cout << endl;
    return;
}

// Deletion at head
template <class Type>
Type LinkedList<Type>::deleteAtHead()
{
    if (this->headIdx == -1)
    {
        cout << "Underflow Error\n";
        return Type();
    }
    int idx = this->headIdx;
    headIdx = nodes[headIdx].next;
    return nodes[idx].val;
}

// Deletion at Tail
template <class Type>
Type LinkedList<Type>::deleteAtTail()
{
    if (this->headIdx == -1)
    {
        cout << "Underflow Error\n";
        return Type();
    }
    int idx = this->headIdx;
    int prev;
    while (nodes[idx].next != -1)
    {
        prev = idx;
        idx = nodes[idx].next;
    }
    nodes[prev].next = -1;
    return nodes[idx].val;
}

// Delete Nth Node
template <class Type>
Type LinkedList<Type>::deleteNthNode(int n)
{
    if (this->headIdx == -1)
    {
        cout << "Underflow Error\n";
        return Type();
    }
    else if (n < 1 || n > this->size())
    {
        cout << n << "th Location Node does not Exist\n";
        return Type();
    }
    else if (n == 1)
    {
        return deleteAtHead();
    }
    int prev;
    int count = 1;
    int idx = this->headIdx;
    while (count < n)
    {
        prev = idx;
        idx = nodes[idx].next;
        count++;
    }
    if (idx == -1)
        return deleteAtTail();
    nodes[prev].next = nodes[idx].next;
    return nodes[idx].val;
}

// Insertion After Nth Node
template <class Type>
void LinkedList<Type>::insertAfterNthNode(Type val, int n)
{
    if (n > this->size() + 1 || n < 0)
    {
        cout << "Location of Insertion do not exist\n";
        return;
    }
    ListNode<Type> newNode(val);
    nodes.push_back(newNode);
    int idx = nodes.size() - 1;
    int ptr = headIdx;
    int count = 0;
    int prev;
    // Insert at Head
    if (n == 0)
    {
        insertAtHead(val);
        return;
    }
    while (count < n && ptr != -1)
    {
        count++;
        prev = ptr;
        ptr = nodes[ptr].next;
    }
    nodes[prev].next = idx;
    nodes[idx].next = ptr;
}

// Insert Before Nth Node
template <class Type>
void LinkedList<Type>::insertBeforeNthNode(Type val, int n)
{
    insertAfterNthNode(val, n - 1);
}

// Reverse the Linked List
template <class Type>
void LinkedList<Type>::reverse()
{
    if (headIdx == -1)
    {
        cout << "LL is empty" << endl;
        return;
    }

    int prev = -1;
    int curr = headIdx;
    int next;

    while (curr != -1)
    {
        next = nodes[curr].next;
        nodes[curr].next = prev;
        prev = curr;
        curr = next;
    }

    headIdx = prev;
}
