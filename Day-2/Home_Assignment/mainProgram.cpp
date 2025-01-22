#include "functionsOfLinkedList.cpp"

void showMenu() {
    cout << "\n----- Linked List Operations -----\n";
    cout << "1. Insert at Head\n";
    cout << "2. Insert at Tail\n";
    cout << "3. Insert After Nth Node\n";
    cout << "4. Insert Before Nth Node\n";
    cout << "5. Delete at Head\n";
    cout << "6. Delete at Tail\n";
    cout << "7. Delete Nth Node\n";
    cout << "8. Display List\n";
    cout << "9. Reverse List\n";
    cout << "10. Count Nodes\n";
    cout << "11. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    LinkedList<int> list;
    int choice, value, position;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                list.insertAtHead(value);
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                list.insertAtTail(value);
                break;
            case 3:
                cout << "Enter value and position to insert after: ";
                cin >> value >> position;
                list.insertAfterNthNode(value, position);
                break;
            case 4:
                cout << "Enter value and position to insert before: ";
                cin >> value >> position;
                list.insertBeforeNthNode(value, position);
                break;
            case 5:
                cout << "Deleted value from head: " << list.deleteAtHead() << endl;
                break;
            case 6:
                cout << "Deleted value from tail: " << list.deleteAtTail() << endl;
                break;
            case 7:
                cout << "Enter position of node to delete: ";
                cin >> position;
                cout << "Deleted value: " << list.deleteNthNode(position) << endl;
                break;
            case 8:
                cout << "Linked List: ";
                list.display();
                break;
            case 9:
                list.reverse();
                cout << "Linked List reversed.\n";
                break;
            case 10:
                cout << "Number of nodes: " << list.size() << endl;
                break;
            case 11:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    }

    return 0;
}
