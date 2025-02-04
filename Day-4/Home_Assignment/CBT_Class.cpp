#include <iostream>
using namespace std;

template <class Type>
class CBT{
    Type* info;
    int root;
    int capacity;
    int last;
public:
    // Parameterized Constructor
    CBT(int capacity){
        info = new Type[capacity+1];
        this->capacity = capacity;
        this->root = 0;
        this->last = 0;
    }
    // Member Functions
    int countAllNodes();
    void preOrderTraversal(int ptr = 1);
    void inOrderTraversal(int ptr = 1);
    void postOrderTraversal(int ptr = 1);
    void insertNode(Type val);
    Type deleteNodeByVal(Type val);
    int searchNode(Type val);
    void levelOrderTraversal();
    int heightOfNode(Type val);
    int depthOfNode(Type val);
    bool checkEmpty();
    void makeEmpty();
    int parentNode(Type val);
    void leftChild(Type val);
    void rightChild(Type val);
    void siblingNode(Type val);
    int countLeafNodes();
    int countInternalNodes();
    int countNodesHavingOneChild();
    int countNodesHavingTwoChild();
};