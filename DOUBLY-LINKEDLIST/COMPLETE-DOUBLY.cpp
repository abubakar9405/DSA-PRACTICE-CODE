#include<iostream>
using namespace std;
// NOT IN WORKING CONDITION YET...
class NODE{
    public:
int data;
NODE *next;
NODE *previous;
void Traversal_DOUBLY_LINKEDLIST(){//traversing through the list
NODE * temp=this;
//hanlding single element.
if (temp->next==NULL)
{
   cout<<"your linked list has only one element \n"<< temp->data;
}
else{
    cout<<"YOUR LINKED LIST IS AS FOLLOWS\n";
do{
cout<<temp->data<<" \n";
temp=temp->next;
}while(temp!=NULL);
}
}
void INSERTION(){
    //HEAD OF THE LINKED LIST WILL BE PASSES TO THIS FUNCTION.
    NODE* temp = this;
    cout << "Choose from the following insertions:\n";
    cout << "1) Insertion at head\n";
    cout << "2) Insertion at last\n";
    cout << "3) Insertion at any index\n";
    cout << "4) Complete insertion\n";
    int num;
    cin >> num;

    switch (num) {
        case 1: // Insertion at head
            cout << "Enter value for your head: ";
            cin >> temp->data;
            break;

        case 2: // Insertion at tail
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new NODE();
            temp->next->previous = temp;
            temp = temp->next;
            temp->next = nullptr;
            cout << "Enter data for your tail: ";
            cin >> temp->data;
            break;

        case 3: // Insertion at any specific index
            int index;
            cout << "Enter index at which you want to enter value: ";
            cin >> index;
            temp = this;
            int count = 0;

            if (index == 0) {
                cout << "For insertion at head use option 1.\n";
                break;
            }

            while (temp != nullptr && count < index - 1) {
                temp = temp->next;
                count++;
            }

            if (temp == nullptr || temp->next == nullptr && index != count + 1) {
                cout << "Invalid index. For insertion of head or tail use other options.\n";
                break;
            }

            NODE* newNode = new NODE();
            cout << "Enter value for index " << index << ": ";
            cin >> newNode->data;
            newNode->next = temp->next;
            newNode->previous = temp;
            if (temp->next != nullptr) {
                temp->next->previous = newNode;
            }
            temp->next = newNode;
            break;

        case 4: // Complete insertion
            count = 0;
            temp = this;
            while (temp != nullptr) {
                temp = temp->next;
                count++;
            }

            temp = this;
            cout << "Enter your complete linked list with " << count << " nodes:\n";
            for (int i = 0; i < count; ++i) {
                cout << "Enter value for node " << i + 1 << ": ";
                cin >> temp->data;
                temp = temp->next;
            }
            break;

        default:
            cout << "Invalid choice\n";
            break;
    }
       }

};

int main(){
NODE *head=new NODE();
NODE *second=new NODE();
NODE *third=new NODE();
NODE *fourth=new NODE();
//this mentioned code is only for one element linked list:
/*head->data=5
head->previous=NULL;
head->next=NULL;
head->Traversal_DOUBLY_LINKEDLIST();*/  

//handling head.
// head->data=4;
head->previous=NULL;
head->next=second;
//handling second.
// second->data=1;
second->previous=head;
second->next=third;
//handling third.
// third->data=5;
third->previous=second;
third->next=fourth;
//handling fourth
// fourth->data=7;
fourth->previous=third;
fourth->next=NULL;
head->INSERTION();
head->Traversal_DOUBLY_LINKEDLIST();



delete head;
delete second;
delete third;
delete fourth;
    
}