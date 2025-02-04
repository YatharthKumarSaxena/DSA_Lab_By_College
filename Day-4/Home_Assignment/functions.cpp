#include "CBT_Class.cpp"

template <class Type>
bool CBT<Type>::checkEmpty(){
    return (root == 0);
}

template <class Type>
void CBT<Type>::makeEmpty(){
    this->root = 0;
    this->last = 0;
}

template <class Type>
int CBT<Type>::countAllNodes(){
    return this->last;
}

template <class Type>
void CBT<Type>::insertNode(Type val){
    if (last >= capacity) {
        int newCapacity = capacity * 2;
        Type* newInfo = new Type[newCapacity + 1];
        for (int i = 1; i <= last; i++) {
            newInfo[i] = info[i];
        }
        delete[] info;
        info = newInfo;
        capacity = newCapacity;
    }
    if(root == 0){
        root = 1;
    }
    last++;
    info[last] = val;
    return;
}

template <class Type>
int CBT<Type>::searchNode(Type val){
    if(this->checkEmpty())return -1;
    for(int i=1;i<=last;i++){
        if(info[i]==val){
            return i;
        }
    }
    return -1;
}

template <class Type>
Type CBT<Type>::deleteNodeByVal(Type val){
    if(this->checkEmpty()){
        cout<<"Underflow Error\n";
        return Type();
    }
    int idx = searchNode(val);
    if(idx == -1){
        cout<<"No value of "<<val<<" exists in our Complete Binary Tree\n";
        return Type();
    }
    info[idx] = info[last];
    last--;
    cout<<"Value deleted Successfully from Tree\n";
    return val;
}

template <class Type>
int CBT<Type>::parentNode(Type val){
    int idx = searchNode(val);
    if(idx == -1){
        cout<<"No value of "<<val<<" exists in our Complete Binary Tree\n";
        return -1;
    }
    if(idx == 1){
        cout<<"Entered Node is the root node\n";
        cout<<"So no parent node exists\n";
        return -1;
    }
    cout<<"Parent Node Exists\n";
    return idx/2;
}

template <class Type>
void CBT<Type>::leftChild(Type val){
    int idx = searchNode(val);
    if(idx == -1){
        cout<<"No value of "<<val<<" exists in our Complete Binary Tree\n";
        return;
    }
    int check = 2*idx;
    if(check<=last){
        cout<<"Left Child Exists for Node whose value is "<<info[check]<<endl;
    }
    else{
        cout<<"No Left Child Node Exists\n";
    }
}

template <class Type>
void CBT<Type>::rightChild(Type val){
    int idx = searchNode(val);
    if(idx == -1){
        cout<<"No value of "<<val<<" exists in our Complete Binary Tree\n";
        return;
    }
    int check = 2*idx+1;
    if(check<=last){
        cout<<"Right Child Node Exists for Node whose value is "<<info[check]<<endl;
    }
    else{
        cout<<"No Right Child Node Exists\n";
    }
}

template <class Type>
void CBT<Type>::siblingNode(Type val){
    int idx = searchNode(val);
    if(idx == -1){
        cout<<"No value of "<<val<<" exists in our Complete Binary Tree\n";
        return;
    }
    if(idx == 1){
        cout<<"Entered Node is Root Node\n";
        cout<<"So no Sibling Exists\n";
        return;
    }
    int a = idx-1;
    int b = idx+1;
    int par = idx/2;
    if(par == b/2){
        cout<<"Entered Node is Left Node\n";
        if(b<=last){
            cout<<"Right Sibling Node Exists having value "<<info[b]<<endl;
        }
        else{
            cout<<"No Right Sibling Node Exists\n";
        }
    }
    else{
        cout<<"Entered Node is Right Node\n";
        cout<<"Left Sibling Node Exists having value "<<info[a]<<endl;
    }
}

template <class Type>
void CBT<Type>::preOrderTraversal(int ptr){
    if(ptr>last)return;
    cout<<info[ptr]<<" ";
    preOrderTraversal(2*ptr);
    preOrderTraversal(2*ptr+1);
}

template <class Type>
void CBT<Type>::inOrderTraversal(int ptr){
    if(ptr>last)return;
    inOrderTraversal(2*ptr);
    cout<<info[ptr]<<" ";
    inOrderTraversal(2*ptr+1);
}

template <class Type>
void CBT<Type>::postOrderTraversal(int ptr){
    if(ptr>last)return;
    postOrderTraversal(2*ptr);
    postOrderTraversal(2*ptr+1);
    cout<<info[ptr]<<" ";
}

template <class Type>
int CBT<Type>::depthOfNode(Type val){
    int idx = searchNode(val);
    if(idx == -1){
        cout<<"No value of "<<val<<" exists in our Complete Binary Tree\n";
        return -1;
    }
    int count = -1;
    while(idx){
        idx/=2;
        count++;
    }
    return count;
}

template <class Type>
int CBT<Type>::heightOfNode(Type val){
    int idx = searchNode(val);
    if(idx == -1){
        cout<<"No value of "<<val<<" exists in our Complete Binary Tree\n";
        return -1;
    }
    int count = -1;
    while(idx<=last){
        idx*=2;
        count++;
    }
    return count;
}

// Display Compltete Binary Tree but LevelWise
template <class Type>
void CBT<Type>::levelOrderTraversal(){
    if(this->checkEmpty()){
        cout<<"Your Binary Tree is Empty\n";
        return;
    }
    int checkPoint = -1;
    int space = 0;
    for(int i=1;i<=last;i++){
        cout<<info[i]<<' ';
        checkPoint++;
        if(space == checkPoint){
            if(space==0)space += 2;
            else space += (space * 2);
            cout<<endl;
        }
    }
    return;
}

template <class Type>
int CBT<Type>::countNodesHavingOneChild(){
    return (last+1)%2;
}

template <class Type>
int CBT<Type>::countInternalNodes(){
    return last/2;
}

template <class Type>
int CBT<Type>::countNodesHavingTwoChild(){
    return this->countInternalNodes() - this->countNodesHavingOneChild();
}

template <class Type>
int CBT<Type>::countLeafNodes(){
    return this->countAllNodes()-this->countInternalNodes();
}