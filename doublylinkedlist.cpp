#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Doubly linked list
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node at the end of the list
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the list
    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Function to perform insertion sort
    void insertionSort() {
        if (!head || !head->next) // If list is empty or has only one element, it is already sorted
            return;

        Node *curr = head->next, *insertionPointer;

        while (curr) {
            int key = curr->data;
            insertionPointer = curr->prev;
            
            // Move elements of the sorted part of the list that are greater than the key, to one position ahead of their current position
            while (insertionPointer && insertionPointer->data > key) {
                insertionPointer->next->data = insertionPointer->data;
                insertionPointer = insertionPointer->prev;
            }

            // Insert the current element into the correct position in the sorted part of the list
            if (insertionPointer == nullptr) {
                head->data = key;
            } else {
                insertionPointer->next->data = key;
            }

            curr = curr->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertEnd(5);
    dll.insertEnd(2);
    dll.insertEnd(9);
    dll.insertEnd(1);
    dll.insertEnd(6);

    cout << "Original list: ";
    dll.display();

    dll.insertionSort();

    cout << "Sorted list: ";
    dll.display();

    return 0;
}
