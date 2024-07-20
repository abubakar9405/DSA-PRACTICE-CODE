#include <iostream>
using namespace std;

class stack {
public:
    int size;
    int top;
    int* arr;

    stack(int size) {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }

    ~stack() {
        delete[] arr;
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == size - 1;
    }

    void push(int num) {
        if (is_full()) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = num;
    }

    int pop() {
        if (is_empty()) {
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top--];
    }

    void traverse_stack() {
        if (is_empty()) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void print_status() {
        cout << "Stack is " << (is_empty() ? "empty" : "not empty") << "\n";
        cout << "Stack is " << (is_full() ? "full" : "not full") << "\n";
    }
};

int main() {
    stack* sp = new stack(10);
    cout << "STACK HAS BEEN CREATED SUCCESSFULLY\n";
    cout << "Checking empty and full status before updating\n";
    sp->print_status();
    //IF YOU WANT USER INPUT IN  STACK UNCOMMENT THE CODE GIVEN BELOW...
//int temp_Size;
// cout<<"enter how many element you want to enter in your stack\n";
// cout<<"max capacity of stack for now is 10\n";
// cin>>temp_Size;
// if (temp_Size>10&&temp_Size<1)
// {
//     cout<<"invalid input\n";
// }
// int j;//to input value in the loop for stack ...
// for(int i=0;i<temp_Size;i++){
//   cout<<"enter your value "<<i+1<<" to fill up stack \n";
//    cin>>j;
//    sp->push(j);
//    }

    sp->push(10);
    sp->push(20);
    sp->push(30);
    sp->push(40);
    sp->push(50);
    sp->push(60);
    sp->push(70);
    sp->push(80);
    sp->push(90);
    sp->push(100);

    cout << "TRAVERSING BEFORE POPPING\n";
    sp->traverse_stack();
    sp->print_status();

    sp->pop();
    sp->pop();
    sp->pop();

    cout << "TRAVERSING AFTER POPPING\n";
    sp->traverse_stack();
    sp->print_status();

    delete sp;
    return 0;
}
