#include<iostream>
using namespace std;


class stack
{
 public:
 int top,size;
 int *arr;
 int stack_IS_EMPTY(){
stack*temp=this;
if (temp->top!=-1)
{
    cout<<"your stack is not empty\n";
   return -1;
   cout<<endl;
}
else{
    cout<<"YOUR STACK IS EMPTY\n";
    return 1;
    cout<<endl;
}
 }
 int STACK_IS_FULL(){
    stack *temp=this;
    if (temp->top==temp->size-1)
    {
        cout<<"YOUR STACK IS FULL\n";
        return 1;
        cout<<"\n";
    }
    else{
        cout<<"NO YOUR STACK HAS SPACE AVAILABLE \n";
        return -1;
        cout<<endl;
    }
 }
 int STACK_PUSH(){
    stack * temp=this;
    int count=-1;
    int rand;
    cout<<"how many  element you want to input in your array of size : "<<size<<"\n";
    cin>>rand;
    for (int  i = 0; i <rand ; i++)
    {
        cin>>temp->arr[i];
        count++;
    }
    temp->top=count;
    return top;
    
 }

};



int main(){
//   stack S;
//   S.size=80;
//   S.top=-1;
//   S.arr=new int[S.size];
   stack *S;
   S->size=6;
   S->top=-1;
  S->arr=new int[S->size];
  //TAKING INPUT FROM OUR USER OF STACK DATA...
  S->STACK_PUSH();
  //CHECK IF STACK IS EMPTY OR NOT...
  cout<<"empty check:\n";
  S->stack_IS_EMPTY();
  //CHECK IF STACK IS FULL OR NOT...
  cout<<"capacity check:\n";
  S->STACK_IS_FULL();



}