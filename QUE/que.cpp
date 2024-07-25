#include<iostream>
using namespace std;
//GLOBAL VARIABLE
int capacity = 10;//suze of queue can be updated by capacity

class QUE {
public:
    int *arr, tail, top;

    // Constructor with default values
    QUE() : top(-1), tail(-1) {
        arr = new int[capacity];
    }

    // Destructor
    ~QUE() {
        delete[] arr;
    }

    // ENQUE method
    void ENQUE(int val) {
        if (ISFULL()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (ISEMPTY()) {
            top = 0;
        }
        tail++;
        arr[tail] = val;
    }

    // DEQUE method (needs to be implemented)
    void DEQUE() {
        if (ISEMPTY()) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (top == tail) {
            top = -1;
            tail = -1;
        } else {
            top++;
        }
    }

    // Check if the queue is empty
    int ISEMPTY() {
        return (top == -1) && (tail == -1);
    }

    // Check if the queue is full
    int ISFULL() {
        return tail == capacity - 1;
    }

    // Get the front element
    int FRONT() {
        if (!ISEMPTY()) {
            return arr[top];
        }
        return -1; // Indicate an error if the queue is empty
    }

    // Get the rear element
    int REAR() {
        if (!ISEMPTY()) {
            return arr[tail];
        }
        return -1; // Indicate an error if the queue is empty
    }
};

int main() {
    QUE q;
     q.ENQUE(1);
     q.ENQUE(2);
     q.ENQUE(3);
     q.ENQUE(4);
     q.ENQUE(5);
     q.ENQUE(6);
     q.ENQUE(7);
     q.ENQUE(8);
     q.ENQUE(9);
     q.ENQUE(10);
    // Q.ENQUE(11); TO CHECK OVERFLOW CONDITION...
    //use this code to input value in the que by user...
    //  for (int  i = 0; i < capacity; i++)
    // {
    //     int j;
    //     cout<<"enter value for your que at postion "<<i+1<< " :";
    //      cin>>j;
    //    q.ENQUE(j);
    // }
    cout << "Front: " << q.FRONT() << endl; // Should print 1
    cout << "Rear: " << q.REAR() << endl;   // Should print 3
    q.DEQUE();
    cout << "Front after dequeue: " << q.FRONT() << endl;
     cout << "Rear: " << q.REAR() << endl;  
//     q.DEQUE();
//     q.DEQUE();
//     q.DEQUE();
//     q.DEQUE();
//     q.DEQUE();
//     q.DEQUE();
//     q.DEQUE();
//     q.DEQUE();
//     q.DEQUE();
//     q.DEQUE();//to check under flow condition
//     cout << "Front after dequeue: " << q.FRONT() << endl; 
//  cout << "Rear after dequeue : " << q.REAR() << endl;  
    return 0;
}
