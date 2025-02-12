template <class Type>
class TreeNode{
public:
    // Data Members
    Type val;
    TreeNode<Type>* left;
    TreeNode<Type>* right;
    // Parametrized Constructor
    TreeNode(Type val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

template <class Type>
class BinaryTree{
    // Data Members
    TreeNode<Type>* root;
public:
    // Default Constructor
    BinaryTree(){
        this->root = NULL;
    }
    // Member Function
    void createRoot(Type val);
    void insertNode(Type val,string loc);
    void preOrder();
    void inOrder();
    void postOrder();
    TreeNode<Type>* returnRoot();
};