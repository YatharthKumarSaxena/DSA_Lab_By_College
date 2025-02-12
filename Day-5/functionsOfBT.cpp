#include "Binary_Tree.cpp"
#include <algorithm>

template <class Type>
TreeNode<Type>* BinaryTree<Type>::returnRoot(){
    return this->root;
}

template <class Type>
void BinaryTree<Type>::createRoot(Type val){
    TreeNode<Type>* temp = new TreeNode<Type>(val);
    root = temp;
    cout<<"Root inserted Successfully\n";
}

template <class Type>
void BinaryTree<Type>::preOrder(TreeNode<Type>* root){
    if(!root)return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

template <class Type>
void BinaryTree<Type>::inOrder(TreeNode<Type>* root){
    if(!root)return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

template <class Type>
void BinaryTree<Type>::postOrder(TreeNode<Type>* root){
    if(!root)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

template <class Type>
void BinaryTree<Type>::insertNode(Type val,string loc){
    TreeNode<Type>* temp = root;
    TreeNode<Type>* parent = root;
    transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
    for(int i=0;i<loc.length();i++){
        if(!temp){
            cout<<"Wrong Location Entered By You\n"<<"So Insertion not possible\n";
            return;
        }
        else if(loc[i]=='r'){
            parent = temp;
            temp = temp->right;
        }
        else if(loc[i]=='l'){
            parent = temp;
            temp = temp->left;
        }
        else{
            cout<<"Invalid Location Entered By you\n";
            cout<<"Insertion Not Possible\n";
            return;
        }
    }
    if(!temp){
        TreeNode<Type>* newNode = new TreeNode<Type>(val);
        cout<<"Insertion Done Successfully\n";
        if(loc[loc.length()-1] == 'r'){
            parent->right = newNode;
        }
        else{
            parent->left = newNode;
        }
    }
    else{
        cout<<"Node already exists at your Entered Location\n";
        cout<<"Insertion not possible\n";
    }
}