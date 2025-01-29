#include "functions.cpp"

void displayMenu(){
    cout<<"\n--------------- Main Menu ---------------\n";
    cout<<"1. Insert Node\n";
    cout<<"2. Search Node by Value\n";
    cout<<"3. To check parent node for a Node by its value\n";
    cout<<"4. To check child node for a Node by its value\n";
    cout<<"5. PreOrder Traversal of Tree\n";
    cout<<"6. InOrder Traversal of Tree\n";
    cout<<"7. PostOrder Traversal of Tree\n";
    cout<<"8. LevelOrder Traversal of Tree\n";
    cout<<"9. Level order traveral of nth Level in BST\n";
    cout<<"10. Delete a Node by Value\n";
    cout<<"11. To check Sibling Node of a Node by value\n";
    cout<<"12. Total number of nodes have one child in BST\n";
    cout<<"13. Total number of nodes have two child in BST\n";
    cout<<"14. Total number of leaf nodes in BST\n";
    cout<<"15. To check Tree is Empty\n";
    cout<<"16. To Make Tree Empty\n";
    cout<<"17. To find height of a Node by its value\n";
    cout<<"18. To find depth of a Node by its value\n";
    cout<<"19. Total Number in Nodes in BST\n";
    cout<<"20. Node with maximum value in BST\n";
    cout<<"21. Node with minimum value in BST\n";
    cout<<"22. Inorder Predecessor of the Node in BST\n";
    cout<<"23. InOrder Successor of the Node in BST\n";
    cout<<"24. Value of Root Node In BST\n";
    cout<<"25. Node Type\n";
    cout<<"0. To Exit main program\n";
}

int main(){
    BST<int>B;
    while(true){
        displayMenu();
        int choice;
        cout<<"\nPlease enter your choice -";
        cin>>choice;
        if(choice == 0)break;
        else if(choice == 1){
            int val;
            cout<<"\nPlease enter the value of Node you want to insert:- ";
            cin>>val;
            B.insertNode(val);
        }
        else if(choice == 2){
            int val;
            cout<<"\nPlease enter the value of Node you want to search:- ";
            cin>>val;
            bool flag = B.searchNode(val);
            if(flag)cout<<"Node Exists\n";
            else cout<<"Node does not exist\n";
        }
        else if(choice == 3){
            int val;
            cout<<"\nPlease enter the value of Node for which you want to find its Parent Node:- ";
            cin>>val;
            TreeNode<int>* temp = new TreeNode<int>(val);
            B.parentNode(temp);
        }
        else if(choice == 4){
            int val;
            cout<<"\nPlease enter the value of Node for which you want to find its child Node:- ";
            cin>>val;
            TreeNode<int>* temp = new TreeNode<int>(val);
            B.childNode(temp);
        }
        else if(choice == 5){
            TreeNode<int>* root = B.returnRoot();
            if(root)B.preOrderTraversal(root);
            else cout<<"Your BST is Empty\n";
        }
        else if(choice == 6){
            TreeNode<int>* root = B.returnRoot();
            if(root)B.inOrderTraversal(root);
            else cout<<"Your BST is Empty\n";
        }
        else if(choice == 7){
            TreeNode<int>* root = B.returnRoot();
            if(root)B.postOrderTraversal(root);
            else cout<<"Your BST is Empty\n";
        }
        else if(choice == 8){
            TreeNode<int>* root = B.returnRoot();
            B.levelOrderTraversal(root);
        }
        else if(choice == 9){
            TreeNode<int>* root = B.returnRoot();
            int n;
            cout<<"Please enter the Level of BST you want to print:- ";
            cin>>n;
            if(root)B.nthLevelOrderTraversal(root,n);
            else cout<<"Your BST is Empty\n";
            cout<<endl;
        }
        else if(choice == 10){
            int val;
            cout<<"\nPlease enter the value of Node you want to delete:- ";
            cin>>val;
            bool flag = B.searchNode(val);
            if(flag){
                cout<<"Value deleted Successfully from BST:- "<<B.deleteNode(val);
            }
            else cout<<"No Node of value"<<val<<" exists in BST\n";
        }
        else if(choice == 11){
            int val;
            cout<<"\nPlease enter the value of Node you want to find its sibling:- ";
            cin>>val;
            TreeNode<int>* temp = new TreeNode<int>(val);
            B.siblingNode(temp);
        }
        else if(choice == 12){
            TreeNode<int>* root = B.returnRoot();
            cout<<"Total number of nodes have one child in BST:- "<<B.countNodesHavingOneChild(root);
        }
        else if(choice == 13){
            TreeNode<int>* root = B.returnRoot();
            cout<<"Total number of nodes have two child in BST:- "<<B.countNodesHavingTwoChild(root);
        }
        else if(choice == 14){
            TreeNode<int>* root = B.returnRoot();
            cout<<"Total number of leaf nodes in BST:- "<<B.countLeafNodes(root);
        }
        else if(choice == 15){
            bool flag = B.checkEmpty();
            if(flag)cout<<"Yes your Tree is empty\n";
            else cout<<"Your Tree is not empty\n";
        }
        else if(choice == 16){
            TreeNode<int>* root = B.returnRoot();
            if(root)cout<<"Your BST is now empty\n";
            else cout<<"Your BST is already empty\n";
        }
        else if(choice == 17){
            int val;
            cout<<"\nPlease enter the value of Node you want to find its height:- ";
            cin>>val;
            TreeNode<int>* temp = new TreeNode<int>(val);
            cout<<"The height of Node having value "<<val<<" is "<<B.heightOfNode(temp);
        }
        else if(choice == 18){
            int val;
            cout<<"\nPlease enter the value of Node you want to find its depth:- ";
            cin>>val;
            TreeNode<int>* temp = new TreeNode<int>(val);
            cout<<"The depth of Node having value "<<val<<" is "<<B.depthOfNode(temp);
        }
        else if(choice == 19){
            TreeNode<int>* root = B.returnRoot();
            cout<<"Total number of nodes in BST:- "<<B.countNode(root);
            cout<<endl;
        }
        else if(choice == 20){
            TreeNode<int>* root = B.returnRoot();
            if(root)cout<<"Maximum value of node in BST:- "<<B.maxNode()<<endl;
            else cout<<"Tree is Empty\n";
        }
        else if(choice == 21){
            TreeNode<int>* root = B.returnRoot();
            if(root)cout<<"Maximum value of node in BST:- "<<B.minNode()<<endl;
            else cout<<"Tree is Empty\n";
        }
        else if(choice == 22){
            int val;
            cout<<"\nPlease enter the value of Node you want to find its inorder Predecessor:- ";
            cin>>val;
            TreeNode<int>* temp = new TreeNode<int>(val);
            TreeNode<int>* ans = B.inorderPredecessorNode(temp);
            cout<<"InOrder Predecessor of the Node is Node with value "<<ans->val<<endl;
        }
        else if(choice == 23){
            int val;
            cout<<"\nPlease enter the value of Node you want to find its inorder Successor:- ";
            cin>>val;
            TreeNode<int>* temp = new TreeNode<int>(val);
            TreeNode<int>* ans = B.inorderSuccessorNode(temp);
            cout<<"InOrder Successor of the Node is Node with value "<<ans->val<<endl;
        }
        else if(choice == 24){
            TreeNode<int>* temp = B.returnRoot();
            if(temp)cout<<"The value of Root Node:- "<<temp->val<<endl;
            else cout<<"BST is empty\n";
        }
        else if(choice == 25){
            int val;
            cout<<"\nPlease enter the value of Node you want to find its type :- ";
            cin>>val;
            B.nodeType(val);
        }
        else{
            cout<<"Invalid Operation , please try again\n";
        }
    }
    return 0;
}