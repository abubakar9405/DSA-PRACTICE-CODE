#include<iostream>
#include<list>//standard template library...
using namespace std;
//implementing FLYOD's ALGO 
bool IS_CYCLE(){


}

int main(){
list<int> obj;
obj.push_front(1);
obj.push_front(2);
obj.push_front(3);
obj.push_front(4);
obj.push_front(5);
for (int val: obj)
{
    cout<<val<<"->";
}
cout<<"head\n";

}