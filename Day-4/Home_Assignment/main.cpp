#include "functions.cpp"  // Include the CBT class file

void displayMenu() {
    cout << "------------------ Complete Binary Tree ------------------\n";
    cout << "1. Insert Node\n";
    cout << "2. Delete Node\n";
    cout << "3. Pre-order Traversal\n";
    cout << "4. In-order Traversal\n";
    cout << "5. Post-order Traversal\n";
    cout << "6. Level-order Traversal\n";
    cout << "7. Count All Nodes\n";
    cout << "8. Count Leaf Nodes\n";
    cout << "9. Count Internal Nodes\n";
    cout << "10. Count Nodes with One Child\n";
    cout << "11. Count Nodes with Two Children\n";
    cout << "12. Search Node\n";
    cout << "13. Get Height of Node\n";
    cout << "14. Get Depth of Node\n";
    cout << "15. Check if Tree is Empty\n";
    cout << "16. Make Tree Empty\n";
    cout << "17. Get Parent Node\n";
    cout << "18. Get Left Child\n";
    cout << "19. Get Right Child\n";
    cout << "20. Get Sibling Node\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    int capacity;
    cout << "Enter the capacity of the Complete Binary Tree: ";
    cin >> capacity;
    CBT<int> tree(capacity);  // Create CBT object with integer values
    
    int choice;
    int value;
    
    while (true) {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                tree.insertNode(value);
                cout << "Node inserted successfully.\n";
                break;
                
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                tree.deleteNodeByVal(value);
                cout << "Node deleted successfully.\n";
                break;
                
            case 3:
                cout << "Pre-order Traversal: ";
                tree.preOrderTraversal();  // Assuming root is at index 0
                cout << endl;
                break;
                
            case 4:
                cout << "In-order Traversal: ";
                tree.inOrderTraversal();  // Assuming root is at index 0
                cout << endl;
                break;
                
            case 5:
                cout << "Post-order Traversal: ";
                tree.postOrderTraversal();  // Assuming root is at index 0
                cout << endl;
                break;
                
            case 6:
                cout << "Level-order Traversal: \n";
                tree.levelOrderTraversal();
                cout << endl;
                break;
                
            case 7:
                cout << "Total nodes in the tree: " << tree.countAllNodes() << endl;
                break;
                
            case 8:
                cout << "Leaf nodes in the tree: " << tree.countLeafNodes() << endl;
                break;
                
            case 9:
                cout << "Internal nodes in the tree: " << tree.countInternalNodes() << endl;
                break;
                
            case 10:
                cout << "Nodes with one child: " << tree.countNodesHavingOneChild() << endl;
                break;
                
            case 11:
                cout << "Nodes with two children: " << tree.countNodesHavingTwoChild() << endl;
                break;
                
            case 12:
                cout << "Enter the value to search: ";
                cin >> value;
                if (tree.searchNode(value) != -1) {
                    cout << "Node found.\n";
                } else {
                    cout << "Node not found.\n";
                }
                break;
                
            case 13:
                cout << "Enter the value to get height: ";
                cin >> value;
                cout << "Height of node: " << tree.heightOfNode(value) << endl;
                break;
                
            case 14:
                cout << "Enter the value to get depth: ";
                cin >> value;
                cout << "Depth of node: " << tree.depthOfNode(value) << endl;
                break;
                
            case 15:
                if (tree.checkEmpty()) {
                    cout << "The tree is empty.\n";
                } else {
                    cout << "The tree is not empty.\n";
                }
                break;
                
            case 16:
                tree.makeEmpty();
                cout << "Tree is now empty.\n";
                break;
                
            case 17:
                cout << "Enter the value to get parent: ";
                cin >> value;
                cout << "Parent of node: " << tree.parentNode(value) << endl;
                break;
                
            case 18:
                cout << "Enter the value to get left child: ";
                cin >> value;
                tree.leftChild(value);
                break;
                
            case 19:
                cout << "Enter the value to get right child: ";
                cin >> value;
                tree.rightChild(value);
                break;
                
            case 20:
                cout << "Enter the value to get sibling: ";
                cin >> value;
                tree.siblingNode(value);
                break;
                
            case 21:
                cout << "Exiting the program.\n";
                return 0;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}
