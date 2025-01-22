#include "functionsOfLL.cpp"

void displayMainMenu(){
    cout<<"Please enter the choice as per given below:- \n";
    cout<<endl;
    cout<<"------------------Main Menu---------------------\n";
    cout<<"0. Exit Main Program\n";
    cout<<"1. Display Linked List\n";
    cout<<"2. Check current size of Linked List\n";
    cout<<"3. Insert At Head\n";
    cout<<"4. Insert At Tail\n";
    cout<<"5. Insert At Nth Node\n";
    cout<<"6. Insert After Nth Node\n";
    cout<<"7. Insert Before Nth Node\n";
    cout<<"8. Insert After Value\n";
    cout<<"9. Insert Before Value\n";
    cout<<"10. Delete First Node\n";
    cout<<"11. Delete Last Node\n";
    cout<<"12. Delete Nth Node\n";
    cout<<"13. Delete After Nth Node\n";
    cout<<"14. Delete Before Nth Node\n";
    cout<<"15. Delete Node by Value\n";
    cout<<"16. Delete Node After Value\n";
    cout<<"17. Delete Node Before Value\n";
    cout<<"18. Search Node by Value\n";
    cout<<endl;
}
int main(){
    int choice;
    LinkedList<int>LL;
    while(true){
        displayMainMenu();
        cout<<"Please enter your choice :- ";
        cin>>choice;
        if(choice == 0){
            cout<<"Exiting Main Program\n";
            break;
        }
        else if(choice == 1){
            cout<<"Your Linked List is displayed below:- \n";
            LL.display();
        }
        else if(choice == 2){
            cout<<"Your Linked List Current size = "<<LL.size()<<endl;
        }
        else if(choice == 3){
            int val;
            cout<<"Please enter the value to be inserted in Linked List as First Node :- ";
            cin>>val;
            LL.insertAtHead(val);
        }
        else if(choice == 4){
            int val;
            cout<<"Please enter the value to be inserted in Linked List as Last Node :- ";
            cin>>val;
            LL.insertAtEnd(val);
        }
        else if(choice == 5){
            int pos;
            cout<<"Please enter the position where you want to insert node :- ";
            cin>>pos;
            int val;
            cout<<"Please enter the value to be inserted in Linked List at "<<pos<<"th position:- ";
            cin>>val;
            LL.insertAtNthNode(val,pos);
        }
        else if(choice == 6){
            int pos;
            cout<<"Please enter the position where you want to insert after that node :- ";
            cin>>pos;
            int val;
            cout<<"Please enter the value to be inserted in Linked List after "<<pos<<"th position:- ";
            cin>>val;
            LL.insertAfterNthNode(val,pos);
        }
        else if(choice == 7){
            int pos;
            cout<<"Please enter the position where you want to insert before that node :- ";
            cin>>pos;
            int val;
            cout<<"Please enter the value to be inserted in Linked List before "<<pos<<"th position:- ";
            cin>>val;
            LL.insertBeforeNthNode(val,pos);
        }
        else if(choice == 8){
            int pos;
            cout<<"Please enter the value where you want to insert after that node containing this value :- ";
            cin>>pos;
            int val;
            cout<<"Please enter the value to be inserted in Linked List after "<<pos<<" containing node:- ";
            cin>>val;
            LL.insertAfterValue(val,pos);
        }
        else if(choice == 9){
            int pos;
            cout<<"Please enter the value where you want to insert before that node containing this value :- ";
            cin>>pos;
            int val;
            cout<<"Please enter the value to be inserted in Linked List before "<<pos<<" containing node:- ";
            cin>>val;
            LL.insertBeforeValue(val,pos);
        }
        else if(choice == 10){
            cout<<"Deleted First Node : "<<LL.deleteAtHead()<<endl;
        }
        else if(choice == 11){
            cout<<"Deleted Last Node : "<<LL.deleteAtEnd()<<endl;
        }
        else if(choice == 12){
            int pos;
            cout<<"Please enter the position at which you want to delete the node :- ";
            cin>>pos;
            cout<<"Deleted Node: "<<LL.deleteNthNode(pos)<<endl;
        }
        else if(choice == 13){
            int pos;
            cout<<"Please enter the position at which you want to delete after that node :- ";
            cin>>pos;
            cout<<"Deleted Node: "<<LL.deleteAfterNthNode(pos)<<endl;
        }
        else if(choice == 14){
            int pos;
            cout<<"Please enter the position at which you want to delete before that node :- ";
            cin>>pos;
            cout<<"Deleted Node: "<<LL.deleteBeforeNthNode(pos)<<endl;
        }
        else if(choice == 15){
            cout<<"Please enter the value of that node you want to delete :- ";
            int val;
            cin>>val;
            LL.deleteValue(val);
        }
        else if(choice == 16){
            cout<<"Please enter the value to delete the node after that node containing this value :- ";
            int val;
            cin>>val;
            cout<<"Deleted Node:- "<<LL.deleteAfterValue(val)<<endl;
        }
        else if(choice == 17){
            cout<<"Please enter the value to delete the node before that node containing this value :- ";
            int val;
            cin>>val;
            cout<<"Deleted Node:- "<<LL.deleteBeforeValue(val)<<endl;
        }
        else if(choice == 18){
            cout<<"Please enter the value to search the node:- ";
            int val;
            cin>>val;
            int pos = LL.searchNode(val);       
            if(pos != -1)cout<<"Node is located at "<<pos<<"th position\n";
            else cout<<"Node not found\n";
        }
        else{
            cout<<"Invalid choice entered by you please try again\n";
        }
    }
}