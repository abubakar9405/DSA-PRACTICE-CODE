#include <iostream>
using namespace std;

class STACK_NODE {
public:
    int data; // Data stored in the node
    STACK_NODE *next; // Pointer to the next node in the stack
    int size; // Maximum size of the stack
    int current_Size; // Current number of elements in the stack

    STACK_NODE(int stack_Size) : size(stack_Size), current_Size(0), next(NULL) {
        // Constructor using initializer list
    }

    bool is_empty() {
        return this->current_Size == 0;
    }

    bool is_FULL() {
        return this->current_Size == this->size;
    }

    int stack_push(int val) {
        if (is_FULL()) {
            cout << "STACK OVERFLOW\n";
            return -1;
        }
        STACK_NODE *p = new STACK_NODE(this->size); // Allocating new node
        p->data = val; // Setting data
        p->next = this->next; // Linking new node to previous top node
        this->next = p; // Updating head
        current_Size++;
        return 0;
    }

    int stack_pop() {
        if (is_empty()) {
            cout << "STACK UNDERFLOW\n";
            return -1; // Indicating empty stack
        }
        STACK_NODE* temp = next; // Pointer to the current top node
        int poppedValue = temp->data; // Storing popped value to return at the end
        next = next->next; // Updating our current working instance
        delete temp; // Deleting the previous instance
        this->current_Size--; // Decrement the current size
        return poppedValue;
    }
};

int main() {
    STACK_NODE *head = new STACK_NODE(5);
    cout << "STACK CREATED SUCCESSFULLY\n";
    head->stack_push(5);
    head->stack_push(6);
    head->stack_push(7);
    head->stack_push(8);
    head->stack_push(10);
   // head->stack_push(11); // To check stack overflow condition at size 5

    cout << "POPPING VALUES\n";
    // while (!head->is_empty()) {
    //     cout << head->stack_pop() << endl;
    // }
    head->stack_pop(); // To check stack underflow condition

    return 0;
}
