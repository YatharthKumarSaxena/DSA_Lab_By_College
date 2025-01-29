#include "functions.cpp"

void displayMenu(){
    cout<<"\n--------------- Main Menu ---------------\n";
    cout<<"1. Insert Node\n";
    cout<<"2. Search Node by Value\n";
    cout<<"3. To check parent node for a Node by its value\n";
    cout<<"4. To check child node for a Node by its value\n";
    cout<<"5. PreOrder Traversal of Tree\n";
    cout<<"6. InOrder Traversal of Tree\n";
    cout<<"6. PostOrder Traversal of Tree\n";
    cout<<"6. LevelOrder Traversal of Tree\n";
    cout<<"7. Level order traveral of nth Level in BST\n";
    cout<<"8. Delete a Node by Value\n";
    cout<<"9. To check Sibling Node of  A Node by value\n";
    cout<<"10. Total number of nodes have one child in BST\n";
    cout<<"11. Total number of nodes have two child in BST\n";
    cout<<"12. Total number of leaf nodes in BST\n";
    cout<<"13. To check Tree is Empty\n";
    cout<<"14. To Make Tree Empty\n";
    cout<<"15. To find height of a Node by its value\n";
    cout<<"15. To find depth of a Node by its value\n";
    cout<<"16. Total Number in Nodes in BST\n";
    cout<<"17. Node with maximum value in BST\n";
    cout<<"18. Node with minimum value in BST\n";
    cout<<"19. Inorder Predecessor of the Node in BST\n";
    cout<<"20. InOrder Successor of the Node in BST\n";
    cout<<"21. Value of Root Node In BST\n";
    cout<<"22. Node Type\n";
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
            
        }
        else if(choice == 4){
            
        }
        else if(choice == 5){
            
        }
        else if(choice == 6){
            
        }
        else if(choice == 7){
            
        }
    }
    return 0;
}