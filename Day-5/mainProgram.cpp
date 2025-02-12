#include "functionsOfBT.cpp"

void displayMenu(){
    cout<<"\n-----------------MAIN MENU-----------------\n";
    cout<<"\n1.To insert Node\n";
    cout<<"2. To display preOrder Traversal\n";
    cout<<"3. To display inOrder Traversal\n";
    cout<<"4. To display postOrder Traversal\n";
    cout<<"5. To exit Tree Making Process\n";
}

template <class Type>
bool checkEquivalentTree(TreeNode<Type>* root1,TreeNode<Type>* root2){
    if(!root1 && !root2)return true;
    else if((!root1 && root2) || (root1 && !root2))return false;
    else if(root1->val != root2->val)return false;
    return (checkEquivalentTree(root1->left,root2->left) && checkEquivalentTree(root1->right,root2->right));
}

int main(){
    int n;
    BinaryTree<int> BT1;
    cout<<"Please enter the value of root node for First Binary Tree :- ";
    cin>>n;
    BT1.createRoot(n);
    TreeNode<int>* root1 = BT1.returnRoot();
    while(true){
        int choice;
        cout<<"Please enter your choice :- ";
        cin>>choice;
        if(choice == 1){
            int val;
            cout<<"Please enter the value you want to insert :- ";
            cin>>val;
            cout<<"Please enter the location where you want to insert this node :- ";
            string loc;
            cin>>loc;
            BT1.insertNode(val,loc);
        }
        else if(choice == 2){
            cout<<"PreOrder Traversal is given below :- \n";
            BT1.preOrder(root1);
            cout<<endl;
        }
        else if(choice == 3){
            cout<<"InOrder Traversal is given below :- \n";
            BT1.inOrder(root1);
            cout<<endl;
        }
        else if(choice == 4){
            cout<<"PostOrder Traversal is given below :- \n";
            BT1.postOrder(root1);
            cout<<endl;
        }
        else if(choice == 5){
            cout<<"Your First Binary Tree is created Successfully\n";
            break;
        }
        else{
            cout<<"Invalid Choice Entered By you , please try again\n";
        }
    }
    int a;
    BinaryTree<int> BT2;
    cout<<"Please enter the value of root node for Second Binary Tree :- ";
    cin>>a;
    BT2.createRoot(a);
    TreeNode<int>* root2 = BT2.returnRoot();
    while(true){
        int choice;
        cout<<"Please enter your choice :- ";
        cin>>choice;
        if(choice == 1){
            int val;
            cout<<"Please enter the value you want to insert :- ";
            cin>>val;
            cout<<"Please enter the location where you want to insert this node :- ";
            string loc;
            cin>>loc;
            BT2.insertNode(val,loc);
        }
        else if(choice == 2){
            cout<<"PreOrder Traversal is given below :- \n";
            BT2.preOrder(root2);
            cout<<endl;
        }
        else if(choice == 3){
            cout<<"InOrder Traversal is given below :- \n";
            BT2.inOrder(root2);
            cout<<endl;
        }
        else if(choice == 4){
            cout<<"PostOrder Traversal is given below :- \n";
            BT2.postOrder(root2);
            cout<<endl;
        }
        else if(choice == 5){
            cout<<"Your Second Binary Tree is created Successfully\n";
            break;
        }
        else{
            cout<<"Invalid Choice Entered By you , please try again\n";
        }
    }
    bool flag = checkEquivalentTree(root1,root2);
    if(flag){
        cout<<"Both Trees are equivalent to each other\n";
    }
    else{
        cout<<"Both Trees are not equivalent to each other\n";
    }
    return 0;
}