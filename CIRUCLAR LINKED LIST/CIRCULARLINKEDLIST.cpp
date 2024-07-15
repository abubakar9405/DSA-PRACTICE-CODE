#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    void circular_traversal() {
        if (!this) return; // Case when linked list is empty
        node* q = this;
        cout << "Data of circular linked list\n";
        do {
            cout << q->data << "\n";
            q = q->next;
        } while (q != this);
    }

    // Other operations of circular linked list
    void insertion_LINKEDLIST() {
        node* q = this;
        cout<< "Input data of your circular linked list\n";
        do {
            cin >> q->data;
            q = q->next;
        } while (q != this);
    }

    node* delete_FUNCTION() {
        cout << "Which type of deletion do you want?\n";
        cout << "1) Delete head\n";
        cout << "2) Delete last\n";
        cout << "3) Delete at any index\n";
        int num;
        cin >> num;

        node* head = this;

        switch (num) {
            case 1: { // Delete head
                if (!head) return nullptr;  // If the list is empty

                if (head->next == head) { // If there is only one node in the list
                    delete head;
                    return nullptr;
                }

                node* temp = head;
                node* last = head;

                // Find the last node
                while (last->next != head) {
                    last = last->next;
                }

                // Point last node's next to the second node
                last->next = head->next;
                head = head->next;
                delete temp;

                return head; // Return the new head pointer
            }
            case 2: { // Delete last
               if (!head) return nullptr;  // If the list is empty

    if (head->next == head) { // If there is only one node in the list
        delete head;
        return nullptr;
    }

    node* current = head;
    node* previous = nullptr;

    // Find the last node
    while (current->next != head) {
        previous = current;
        current = current->next;
    }

    // Point the second last node's next to the head
    previous->next = head;
    delete current;

    return head;
            }
            case 3: { // Delete at any index
			cout<<"head cannot be deleted using this case \n";//head is on 0 index
                int index;
                cout << "Enter the index: ";
                cin >> index;

                if (!head || index < 0) return nullptr; // If the list is empty or index is invalid

                if (index == 0) return delete_FUNCTION(); // If deleting the head node

                node* current = head;
                node* previous = nullptr;

                for (int i = 0; current->next != head && i < index; i++) {
                    previous = current;
                    current = current->next;
                }

                if (current->next == head && index != 0) { // If index is out of range
                    cout << "Index out of range" << endl;
                    return head;
                }

                // Skip the current node
                previous->next = current->next;
                delete current;

                return head;
            }
            default:
                cout << "Invalid option" << endl;
                return head;
        }
    }
};

int main() {
    // Just to access head.
    node* head = new node();
    node* second = new node();
    node* third = new node();
    node* fourth = new node();

    // Link first and second node.
    head->next = second;
    // Link second and third node
    second->next = third;
    // Link third and fourth node
    third->next = fourth;
    // Link fourth and head as its circular
    fourth->next = head;

    // Insert data into linked list
    head->insertion_LINKEDLIST();

    // Perform deletion
    head = head->delete_FUNCTION();

    // Traversal after deletion
    cout << "After deletion:" << endl;
    if (head) {
        head->circular_traversal();
    } else {
        cout << "List is empty." << endl;
    }

    // Clean up the allocated memory if the list is not empty
    if (head) {
        node* current = head;
        do {
            node* next = current->next;
            delete current;
            current = next;
        } while (current != head);
    }
    return 0;
}
