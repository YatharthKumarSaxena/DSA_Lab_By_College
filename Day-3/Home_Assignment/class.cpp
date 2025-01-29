#include <iostream>
using namespace std;

template <class Type>
class TreeNode{
public:
    // Data Members
    Type val;
    TreeNode<Type>* left;
    TreeNode<Type>* right;
    // Parameterized Constructor
    TreeNode(Type val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

template <class Type>
class BST{
    // Data Members
    TreeNode<Type>* root;
public:
    // Default Constructor
    BST(){
        this->root = NULL;
    }
    // Member Functions
    void insertNode(Type val);
    bool searchNode(Type val);
    Type deleteNode(Type val);
    int countNode(TreeNode<Type>* root);
    void preOrderTraversal(TreeNode<Type>* root);
    void inOrderTraversal(TreeNode<Type>* root);
    void postOrderTraversal(TreeNode<Type>* root);
    void levelOrderTraversal(TreeNode<Type>* root);
    Type maxNode();
    Type minNode();
    void nodeType(Type val);
    void childNode(TreeNode<Type>* temp);
    void siblingNode(TreeNode<Type>* temp);
    void parentNode(TreeNode<Type>* temp);
    bool checkEmpty();
    void makeEmptyTree(TreeNode<Type>*& root);
    TreeNode<Type>* returnRoot();
    TreeNode<Type>* inorderSuccessorNode(TreeNode<Type>* temp);
    TreeNode<Type>* inorderPredecessorNode(TreeNode<Type>* temp);
    int countLeafNodes(TreeNode<Type>* root);
    int countNodesHavingOneChild(TreeNode<Type>* root);
    int countNodesHavingTwoChild(TreeNode<Type>* root);
    int heightOfNode(TreeNode<Type>* temp);
    int depthOfNode(TreeNode<Type>* temp);
    void nthLevelOrderTraversal(TreeNode<Type>* root,int level,int curr = 0);
};