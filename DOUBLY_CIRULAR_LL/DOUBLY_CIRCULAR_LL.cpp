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


}