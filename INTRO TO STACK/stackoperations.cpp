#include<iostream>
using namespace std;
class stack
{

public:
   int size;
   int top;
   int *arr;
//IMPLEMENT TWO FUNC IS_FULL AND IS_EMPTY
int IS_EMPTY(){
if (this->top==-1)
{
    cout<<"your stack is empty\n";
    return 1;
}
else{
    cout<<"your stack is not empty\n";
    return 0;
}
}
int  IS_FULL(){
if (this->top==this->size-1)
{
    cout<<"your stack is full\n";
    return 1;
}
cout<<"your stack is not full\n";
return 0; 
}
void push(int num){
    stack*temp=this;
    if (temp->top==temp->size-1)
    {
       cout<<"stack overflow\n";
    }
    else{
        temp->top++;
        temp->arr[this->top]=num;

    }
}
void traverse_stack(){

stack*temp=this;
for (int i = 0; i <temp->size; i++)
{
    cout<<temp->arr[i]<<" \n";
}
}

};

int main(){
stack*sp=new stack();
sp->size=10;//hardcoded size of stack to 10...
sp->top=-1;//top means the highest element of the stack...
sp->arr=new int[sp->size];
cout<<"STACK HAS BEEN CREATED SUCCESSFULLY\n";
cout<<"checking empty full before updating\n";
sp->IS_EMPTY();
sp->IS_FULL();
int temp_Size;
cout<<"enter how many element you want to enter in your stack\n";
cout<<"max capacity of stack for now is 10\n";
cin>>temp_Size;
if (temp_Size>10&&temp_Size<1)
{
    cout<<"invalid input\n";
}
int j;//to input value in the loop for stack ...
for(int i=0;i<temp_Size;i++){
  cout<<"enter your value "<<i+1<<" to fill up stack \n";
   cin>>j;
   sp->push(j);
   }
sp->IS_EMPTY();
sp->IS_FULL();
cout<<"traversing through the stack\n";
sp->traverse_stack();
return 0;


}