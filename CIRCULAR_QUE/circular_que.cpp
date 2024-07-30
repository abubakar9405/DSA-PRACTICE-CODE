#include<iostream>
using namespace std;
class circular_que
{
public:
int *front,*rear,top;//front rear to keep track in a circular manner 
int *arr,capacity;
// dynaic allocation of array to perform the operation
//enque,deque,isfull,isempty
circular_que(int size):capacity(size){
arr=new int[capacity];
}
void is_Empty();
void is_Full();
void Enque();
void Deque();
   
};


int main(){
    
}