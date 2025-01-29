#include "class.cpp"

template <class Type>
void BST<Type>::preOrderTraversal(TreeNode<Type> *root)
{
    if (!root)
    {
        cout << endl;
        return;
    }
    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

template <class Type>
void BST<Type>::inOrderTraversal(TreeNode<Type> *root)
{
    if (!root)
    {
        cout << endl;
        return;
    }
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

template <class Type>
void BST<Type>::postOrderTraversal(TreeNode<Type> *root)
{
    if (!root)
    {
        cout << endl;
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}

template <class Type>
bool BST<Type>::checkEmpty()
{
    if (root)
        return false;
    return true;
}

template <class Type>
Type BST<Type>::maxNode()
{
    if (!root)
        return Type();
    TreeNode<Type> *temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp->val;
}

template <class Type>
Type BST<Type>::minNode()
{
    if (!root)
        return Type();
    TreeNode<Type> *temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->val;
}

template <class Type>
TreeNode<Type> *BST<Type>::returnRoot()
{
    return root;
}

template <class Type>
void BST<Type>::makeEmptyTree(TreeNode<Type> *&root)
{
    while (root)
    {
        makeEmptyTree(root->left);
        makeEmptyTree(root->right);
        delete root;
        root = NULL;
    }
}

template <class Type>
void BST<Type>::insertNode(Type val)
{
    TreeNode<Type> *temp = new TreeNode<Type>(val);
    if (!root)
    {
        root = temp;
        return;
    }
    TreeNode<Type> *ptr = root;
    while (true)
    {
        if (ptr->val == val)
        {
            cout << "Value " << val << " already exists in Tree\n";
            return;
        }
        else if (ptr->val > temp->val)
        {
            if (!ptr->left)
            {
                ptr->left = temp;
                return;
            }
            ptr = ptr->left;
        }
        else
        {
            if (!ptr->right)
            {
                ptr->right = temp;
                return;
            }
            ptr = ptr->right;
        }
    }
}

template <class Type>
bool BST<Type>::searchNode(Type val)
{
    TreeNode<Type> *temp = root;
    while (temp)
    {
        if (temp->val == val)
            return true;
        else if (temp->val > val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

template <class Type>
void BST<Type>::nodeType(Type val)
{
    if (!root)
    {
        cout << "Tree is empty\n";
        return;
    }
    else if (root->val == val)
    {
        cout << "This Node is Root Node\n";
    }
    TreeNode<Type> *temp = root;
    while (temp)
    {
        if (temp->val == val)
        {
            if (!temp->left && !temp->right)
                cout << "This Node is leaf Node\n";
            else
                cout << "This Node is Internal Node\n";
            return;
        }
        else if (temp->val > val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    cout << "No Node of " << val << " exists in Tree\n";
}

template <class Type>
Type BST<Type>::deleteNode(Type val)
{
    if (!root)
    {
        cout << "Underflow Error\n";
        return Type();
    }
    TreeNode<Type> *temp = root;
    TreeNode<Type> *save = root;
    while (temp)
    {
        if (temp->val == val)
        {
            Type value = temp->val;
            if (!temp->left && !temp->right)
            {
                if (save != temp)
                {
                    if (save->left == temp)
                        save->left = NULL;
                    else
                        save->right = NULL;
                }
                else
                {
                    root = NULL;
                }
                delete temp;
            }
            else if (temp->left && temp->right)
            {
                TreeNode<Type> *predecessor = inorderPredecessorNode(temp); // Get predecessor
                temp->val = predecessor->val;                               // Replace temp value with predecessor's value

                // Now, delete predecessor
                TreeNode<Type> *parentOfPredecessor = temp; // Save the parent node
                TreeNode<Type> *track = temp->left;

                // Traverse to rightmost node of left subtree
                while (track->right)
                {
                    parentOfPredecessor = track; // Move parent reference to current node
                    track = track->right;
                }

                // Check if predecessor node is the left child of its parent
                if (parentOfPredecessor->left == track)
                {
                    // If predecessor has a left child, link it to parent's left
                    if (track->left)
                    {
                        parentOfPredecessor->left = track->left;
                    }
                    else
                    {
                        parentOfPredecessor->left = NULL;
                    }
                }
                else
                {
                    // If predecessor is right child, link it to parent's right
                    if (track->left)
                    {
                        parentOfPredecessor->right = track->left;
                    }
                    else
                    {
                        parentOfPredecessor->right = NULL;
                    }
                }

                // Delete predecessor node
                delete track;
            }
            else if (temp->left)
            {
                if (save != temp)
                {
                    if (save->left == temp)
                        save->left = temp->left;
                    else
                        save->right = temp->left;
                }
                else
                {
                    root = root->left;
                }
                delete temp;
            }
            else
            {
                if (save != temp)
                {
                    if (save->left == temp)
                        save->left = temp->right;
                    else
                        save->right = temp->right;
                }
                else
                {
                    root = root->right;
                }
                delete temp;
            }
            return value;
        }
        else if (temp->val > val)
        {
            save = temp;
            temp = temp->left;
        }
        else
        {
            save = temp;
            temp = temp->right;
        }
    }
    cout << "No Node of value " << val << " exists\n";
    return Type();
}

template <class Type>
TreeNode<Type> *BST<Type>::inorderPredecessorNode(TreeNode<Type> *temp)
{
    if (!temp || !temp->left)
    {
        cout << "Sorry No InOrder Predecessor exists for this Node\n";
        return NULL;
    }
    TreeNode<Type> *ptr = temp->left;
    while (ptr->right)
    {
        ptr = ptr->right;
    }
    return ptr;
}

template <class Type>
TreeNode<Type> *BST<Type>::inorderSuccessorNode(TreeNode<Type> *temp)
{
    if (!temp || !temp->right)
    {
        cout << "Sorry No InOrder Successor exists for this Node\n";
        return NULL;
    }
    TreeNode<Type> *ptr = temp->right;
    while (ptr->left)
    {
        ptr = ptr->left;
    }
    return ptr;
}

template <class Type>
void BST<Type>:: childNode(TreeNode<Type>* temp){
    if(!root){
        cout<<"Tree is Empty\n";
        return;
    }
    TreeNode<Type>* ptr = root;
    while(ptr){
        if(temp->val < ptr->val)ptr = ptr->left;
        else if(temp->val > ptr->val)ptr = ptr->right;
        else break;
    }
    if(ptr){
        if(ptr->left){
            cout<<"Left Child Node of "<<ptr->left->val<<" exists\n";
        }
        else {
            cout << "No Left Child Node for this node\n";
        }
        if(ptr->right){
            cout<<"Right Child Node of "<<ptr->right->val<<" exists\n";
        }
        else {
            cout << "No Right Child Node for this node\n";
        }
    }
    else cout<<"Sorry this Node does not exist in your BST\n";
}

template <class Type>
void BST<Type>::parentNode(TreeNode<Type>* temp){
    if(!root){
        cout<<"Tree is Empty\n";
        return;
    }
    if(temp == root){
        cout<<"Given Node is Root Node\n";
        cout<<"So no Parent Node Exits\n";
        return;
    }
    TreeNode<Type>* save = NULL;
    TreeNode<Type>* ptr = root;
    while(ptr){
        if(temp->val < ptr->val){
            save = ptr;
            ptr = ptr->left;
        }
        else if(temp->val > ptr->val){
            save = ptr;
            ptr = ptr->right;
        }
        else break;
    }
    if(ptr){
        cout<<"Parent Node Exists whose value is "<<save->val<<endl;
    }
    else{
        cout<<"No Node of value "<<temp->val<<" Exist in BST\n";
    }
}

template <class Type>
void BST<Type>::siblingNode(TreeNode<Type>* temp){
    if(!root){
        cout<<"Tree is Empty\n";
        return;
    }
    else if(temp == root){
        cout<<"Given Node is the root node\n";
        cout<<"So no Siblings Exists\n";
        return;
    }
    TreeNode<Type>* ptr = root;
    while(ptr){
        if(ptr->left == temp){
            if(ptr->right){
                cout<<"Right Sibling Exists for this Node having value "<<ptr->right->val;
                cout<<endl;
                return;
            }
            else{
                cout<<"Right Sibling does not exist for this Node";
                cout<<endl;
                return;
            }
        }
        else if(ptr->right == temp){
            if(ptr->left){
                cout<<"Left Sibling Exists for this Node having value "<<ptr->left->val;
                cout<<endl;
                return;
            }
            else{
                cout<<"Left Sibling does not exist for this Node";
                cout<<endl;
                return;
            }
        }
        else if(ptr->val >temp->val) ptr = ptr->left;
        else ptr = ptr->right;
    }
    cout<<"No Node of value "<<temp->val<<" Exists in BST\n";
}

template <class Type>
int BST<Type>::countNode(TreeNode<Type>* root){
    if(!root)return 0;
    return 1+countNode(root->left)+countNode(root->right);
}

template <class Type>
int BST<Type>::countLeafNodes(TreeNode<Type>* root){
    if(!root)return 0;
    return ((!root->left && !root->right)?1:0) + countLeafNodes(root->left) + countLeafNodes(root->right);
}

template <class Type>
int BST<Type>::countNodesHavingOneChild(TreeNode<Type>* root){
    if(!root)return 0;
    return (((root->left && !root->right) || (!root->left && root->right))?1:0) + countNodesHavingOneChild(root->left) + countNodesHavingOneChild(root->right);
}

template <class Type>
int BST<Type>::countNodesHavingTwoChild(TreeNode<Type>* root){
    if(!root)return 0;
    return ((root->left && root->right) ?1:0) + countNodesHavingTwoChild(root->left) + countNodesHavingTwoChild(root->right);
}

template <class Type>
int BST<Type>::heightOfNode(TreeNode<Type>* temp){
    if(!temp)return -1;
    return 1+max(heightOfNode(temp->left),heightOfNode(temp->right));
}

template <class Type>
int BST<Type>::depthOfNode(TreeNode<Type>* temp){
    if (!root || !temp) return -1; // Handle cases where the tree or node is NULL
    int count = 0;
    TreeNode<Type>* ptr = root;
    while(ptr!=temp){
        if(ptr->val>temp->val)ptr = ptr->left;
        else ptr = ptr->right;
        count++;
    }
    return count;
}

template <class Type>
void BST<Type>::nthLevelOrderTraversal(TreeNode<Type>* root,int level,int curr){
    if(!root){
        return;
    }
    if(curr == level){
        cout<<root->val<<" ";
    }
    nthLevelOrderTraversal(root->left,level,curr+1);
    nthLevelOrderTraversal(root->right,level,curr+1);
}

template <class Type>
void BST<Type>::levelOrderTraversal(TreeNode<Type>* root){
    if(!root){
        cout<<"Your Tree is Empty\n";
        return;
    }
    int level = heightOfNode(root);
    for(int i=0;i<=level;i++){
        nthLevelOrderTraversal(root,i);
        cout<<endl;
    }
    cout<<endl;
}