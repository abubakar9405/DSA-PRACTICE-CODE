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

};

int main(){
stack*sp=new stack();
sp->size=10;//hardcoded size of stack to 10...
sp->top=-1;//top means the highest element of the stack...
sp->arr=new int[sp->size];
cout<<"STACK HAS BEEN CREATED SUCCESSFULLY\n";
sp->IS_EMPTY();
sp->IS_FULL();
return 0;


}