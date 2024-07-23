#include<iostream>
using namespace std;
class stack_parenthesis_matching
{
public:
//ALL DATA PUBLIC TO AVOID UNCERTAIN BLOCKAGES...
int capacity,top;
char * arr;
    stack_parenthesis_matching(int size):capacity(size),top(-1){//used intializer list 
    arr=new char[capacity];
        }
        bool isFULL(){
            if (this->top==capacity-1)
            {
               return true;//in 0,1
            }
            return false;
        }
        bool isEmpty(){
            if (this->top==-1)
            {
                return true;
            }
            return false;
        }
        int STACK_TOP(){
            return this->arr[this->capacity-1];
        }
        int STACK_BOTTOM(){
            return this->arr[0];
        }
    int push(int val){
if (this->top==capacity-1)
{
    cout<<"STACK OVERFLOW\n";
    return -1;
}
return this->arr[++top]=val;
    }
int pop(){
if (this->top==-1)
{
    cout<<"STACK UNDERFLOW\n";
    return -1;
}
return this->arr[top--];
}


int peek(int pos){
if (this->top-pos+1<0)
        {
            cout<<"NOT A VALID POSITION\n";
        }
       return this->arr[this->top-pos+1];

}
};

int main(){






}