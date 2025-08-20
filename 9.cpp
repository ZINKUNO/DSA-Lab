// Implement linked list and insert and delete an element into the list
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert a node at the end
void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete a node by value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    // If head itself needs to be deleted
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Value not found in list.\n";
        return;
    }

    prev->next = current->next;
    delete current;
}

// Display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main function
int main() {
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Linked List: ";
    display(head);

    cout << "Deleting 20...\n";
    deleteNode(head, 20);

    cout << "Linked List after deletion: ";
    display(head);

    return 0;
}
    