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

    int peek(int pos) {
        if (pos <= 0 || pos > this->current_Size) {
            cout << "Invalid position\n";
            return -1; // Indicating invalid position
        }

        STACK_NODE* temp = this->next; // Start from the top of the stack
        for (int i = 1; i < pos; i++) {
            temp = temp->next; // Move to the next node
        }

        return temp->data; // Return the data of the node at the specified position
    }

    int STACK_TOP(){
        if (is_empty()) {
            cout << "STACK IS EMPTY\n";
            return -1; // Indicating empty stack
        }
        return this->next->data;
    }

    int STACK_BOTTOM() {
        if (is_empty()) {
            cout << "STACK IS EMPTY\n";
            return -1; // Indicating empty stack
        }

        STACK_NODE* temp = this->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->data;
    }

    void display() {
        STACK_NODE* temp = this->next;
        cout << "Stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
    head->display();
    cout<<"peeking at 1 after pushing the data into stack \n";
    cout<<" \n";
    cout<<endl<<head->peek(6);
    cout << "CHECKING STACK TOP AND BOTTOM BEFORE POPPING\n";
    cout << "TOP VALUE OF THE STACK IS: " << head->STACK_TOP() << endl;
    cout << "BOTTOM VALUE OF THE STACK IS: " << head->STACK_BOTTOM() << endl;
    
    // Uncomment this line to check stack overflow condition at size 5
    // head->stack_push(11);

    head->stack_pop(); 
    head->stack_pop(); 
    head->stack_pop(); 
    head->display();

    cout << "\nPEEKING IN THE STACK\n";
    cout << head->peek(2) << endl;
    cout << "CHECKING STACK TOP AND BOTTOM AFTER POPPING \n";
    cout << "TOP VALUE OF THE STACK IS: " << head->STACK_TOP() << endl;
    cout << "BOTTOM VALUE OF THE STACK IS: " << head->STACK_BOTTOM() << endl;

    return 0;
}
