#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;

    node() : data(0), next(nullptr) {}
    ~node() {
        cout << "~node() being called \n";
    }

    void linkedlist_traversal() {
        node* current = this;
        while (current != nullptr) {
            cout << "element: " << current->data << endl;
            current = current->next;
        }
    }

    node* insert_START(node* obj) {
        node* ptr = this;
        ptr->next = obj;
        return ptr;
    }

    node* insert_end(node* lastNode) {
        node* ptr = this;
        lastNode->next = ptr;
        ptr->next = nullptr;
        return lastNode;
    }

    void insert_between(node* leftone, node* rightone) {
        node* ptr = this;
        leftone->next = ptr;
        ptr->next = rightone;
    }

    void insert_after_A_NODE(node* NODE) {
        node* ptr = this;
        ptr->next = NODE->next;
        NODE->next = ptr;
    }

    // Deleting element at start of linked list
    void deletion_START() {
        if (this->next != nullptr) {
            node* temp = this->next;
            this->data = this->next->data;
            this->next = this->next->next;
            delete temp;
        }
        else {
            cout << "This function is only capable of deleting one node at a time\n";
        }
    }

    // Deleting element at specified index
    void deletion_INDEX(int index) {
        if (index == 0 && this->next != nullptr) {
            node* temp = this->next;
            this->data = this->next->data;
            this->next = this->next->next;
            delete temp;
            return;
        }
        else if (index == 0 && this->next == nullptr) {
            cout << "Cannot delete the only node in the list using this method." << endl;
            return;
        }

        node* p = this;
        node* q = this->next;
        for (int i = 0; i < index - 1; i++) {
            if (q == nullptr || q->next == nullptr) {
                cout << "Index out of bounds" << endl;
                return;
            }
            p = p->next;
            q = q->next;
        }

        if (q == nullptr || q->next == nullptr) {
            cout << "Index out of bounds" << endl;
            return;
        }

        p->next = q->next;
        delete q;
    }

    void deletion_Last_element() {
        if (this->next == nullptr) {
            cout << "Cannot delete the only node in the list using this method." << endl;
            return;
        }
        node* p = this;
        node* q = this->next;
        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        p->next = nullptr;
        delete q;
    }
    //case 4 for any certain value
    int deletion_certain_value(int val) {
        node* p = this;
        node* q = this->next;

        // Special case: check if the head node itself contains the value
        if (this->data == val) {
            if (this->next != nullptr) {
                node* temp = this->next;
                this->data = this->next->data;
                this->next = this->next->next;
                delete temp;
                return 1;
            }
            else {
                // If this is the only node and it contains the value
                cout << "Cannot delete the only node in the list using this method." << endl;
                return -1;
            }
        }
        while (q != nullptr) {
            if (q->data == val) {
                p->next = q->next;
                delete q;
                return 1; // Return 1 indicating successful deletion
            }
            p = p->next;
            q = q->next;
        }

        cout << "Value not found in the linked list so the list is the same\n";
        return -1; // Return -1 indicating value not found
    }


      
};
int main() {
    // Allocate memory for the linked list in heap
    node* head = new node();
    node* second = new node();
    node* third = new node();
    node* four = new node();
    node* head1 = new node();
    node* end2 = new node();
    node* MIDDLE = new node();
    node* AFTER = new node();

    // Link nodes
    head->data = 7;
    head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 5;
    third->next = four;
    four->data = 27;
    four->next = nullptr;

  /*  head1->data = 16;
    end2->data = 69;
    MIDDLE->data = 50;
    AFTER->data = 78;
    head1->insert_START(head);
    end2->insert_end(four);
    MIDDLE->insert_between(second, third);
    AFTER->insert_after_A_NODE(third);*/

    cout << "linked list before deletion \n";
    head->linkedlist_traversal();

    /*cout << "linked list after deletion of any specified index element\n";
    head->deletion_INDEX(0);
    head->linkedlist_traversal();*/

    /*cout << "linked list after deletion of last element \n";
    head->deletion_Last_element();
    head->linkedlist_traversal();*/
    cout << "deletion at certain value\n";
    head->deletion_certain_value(47);
    head->linkedlist_traversal();

    // Clean up remaining memory
    /*delete head1;
    delete end2;
    delete MIDDLE;
    delete AFTER;
    delete four;
    delete third;
    delete second;
    delete head;*/

    return 0;
}
