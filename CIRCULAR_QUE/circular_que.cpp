#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int front, rear, size, capacity;

public:
    CircularQueue(int storage): capacity(storage) {
        queue = new int[capacity]; // initializes array dynamically
        front = size = 0;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return (size == capacity);
    }

    bool isEmpty() {
        return (size == 0);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int item = queue[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int frontItem() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[front];
    }

    int rearItem() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[rear];
    }
};

int main() {
    CircularQueue q(5); // Capacity of the circular queue is 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Dequeued: " << q.dequeue() << endl; // Output: Dequeued: 10
    cout << "Front item: " << q.frontItem() << endl; // Output: Front item: 20
    cout << "Rear item: " << q.rearItem() << endl; // Output: Rear item: 50

    q.enqueue(60); // Should work now, as there is space in the queue after dequeue

    return 0;
}
