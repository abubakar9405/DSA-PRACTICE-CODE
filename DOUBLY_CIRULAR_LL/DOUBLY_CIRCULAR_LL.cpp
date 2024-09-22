#include<iostream>
using namespace std;
template<class T>
class DOUBLY_CIRCULAR_LL{
public:
class NODE{
    public:
    //Data members for NODE...
    T data;
    NODE*next;
    NODE*prev;
    NODE(T const element):data(element),next(NULL),prev(NULL){}
};
//data members for LL
NODE*head,*tail;
DOUBLY_CIRCULAR_LL():head(NULL),tail(nullptr){}
void Insertion_At_Start(T const element){
NODE*newnode=new NODE(element);//node containing the data...
NODE*current=head;
if (head==NULL)
{//no element in the list
head=newnode;//head=nwnode
newnode->next=head;
newnode->prev=head;
tail=newnode;
}
else{
    //list has already some head present...
newnode->next=head;//pointing to head
newnode->prev=tail;//prev pointing is always at null at insertion at head...
head->prev=newnode;
tail->next=newnode;
head=newnode;//updating head..
}
}
void Insertion_At_End(T const element){
//handling edge cases
//case-01 only one element in the list
if (head==NULL)
{//no element in the list so
    this->Insertion_At_Start(element);
}
else{// list has some element present in it...
NODE*newnode=new NODE(element);//made new node containing element in it...
NODE*current=head;
while (current->next!=head)
{
    current=current->next;
}
//at tail now...
current->next=newnode;
newnode->prev=current;
newnode->next=head;
tail=newnode;
tail->next=head;
}



}
void Insertion_After(T const v1,T const element){//v1 is the data
NODE*current=head;
NODE*newnode=new NODE(element);
//edge cases
if(head==NULL)
{
    cout<<"no element is present so insertion cannot be processed\n";
    return;
}

while(current->data!=v1){

    current=current->next;
}
//at node after which insertion is required...
NODE*temp;
temp=current->next;
current->next=newnode;
newnode->next=temp;
newnode->prev=current;
tail->next=head;
}
void Del_At_Start(){
//edge cases 
NODE*current=head;
if (head==nullptr)
{
    cout<<"there is nothing to delete \n"
        <<"the list is empty";
    return;
}
if (current->next==NULL)
{
    //only one element in the list...
    delete current;
    current->next=NULL;
    current->prev=NULL;
    head=NULL;
    tail=NULL;
}
else{
head=current->next;
current->next->prev=NULL;
tail->next=head;
delete current;

}
}
void Del_At_End(){
    //if no elements
      NODE*current=head;
    if (head==nullptr)
{
    cout<<"there is nothing to delete \n"
        <<"the list is empty";
    return;
}
if (current->next==NULL)
{
    //only one element in the list...
    delete current;
    current->next=NULL;
    current->prev=NULL;
    head=NULL;
    tail=NULL;
}
else{
    while (current->next->next!=head)
    {
        current=current->next;
    }
    //at one node back from tail...
    NODE*temp=current->next;
    delete temp;
    current->next=head;
    tail=current->next=head;
}
}
void Del_After(T const v1) {
    if (head == nullptr) {
        cout << "There is nothing to delete. The list is empty.\n";
        return;
    }

    NODE* current = head;

    // Find the node with value `v1`
    do {
        if (current->data == v1) {
            break;
        }
        current = current->next;
    } while (current != head);

    if (current->data != v1) {
        cout << "Node with value " << v1 << " not found.\n";
        return;
    }

    // Now current is the node with value v1, so delete the node after it
    NODE* toDelete = current->next;

    // Edge case: If there's only one node or no node after v1
    if (toDelete == head) {
        cout << "Cannot delete after " << v1 << " because it's the only element in the list.\n";
        return;
    }

    // If the node to be deleted is the tail
    if (toDelete == tail) {
        tail = current; // Update tail to the node before the current tail
    }

    // Update the links to bypass the node to be deleted
    current->next = toDelete->next;    
    toDelete->next->prev = current;

    delete toDelete;  // Free memory of the deleted node

    // Re-establish circular property
    tail->next = head;
    head->prev = tail;  // Important to maintain circular doubly linked structure
}



void print(){
    if (head==NULL){return;/*no element in the list*/}    
    NODE*current=head;
    do    
    {
        cout<<current->data<<" -> ";
        current=current->next;
    }while (current!=head);
     cout << "(head)" << endl; // Indicate circularity
    }
};
int main(){
DOUBLY_CIRCULAR_LL<int> obj;
obj.Insertion_At_Start(2);
obj.Insertion_At_Start(3);
obj.Insertion_At_Start(4);
obj.Insertion_At_Start(5);
 obj.Insertion_At_End(7);
 obj.Insertion_At_End(7);
 obj.Insertion_At_End(5);
 obj.Insertion_At_Start(1);
 obj.print();
 obj.Insertion_After(3,12);
obj.print();
cout<<"printing after deletion at start\n";
obj.Del_At_Start();
obj.print();
cout<<"deleting at the end\n";
obj.Del_At_End();
obj.print();
cout<<"deleting NODE after  4 \n";
obj.Del_After(7);
obj.print();

}