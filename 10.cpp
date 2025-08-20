// wap for insertion at begin ,insertion at end ,insertion at given pos ,deletion at begin ,deletion at end,deletion at given pos, and display the element of linklist use switch cases inside do while loop

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Function to insert at beginning
void insertAtBegin(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// Function to insert at end
void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to insert at given position
void insertAtPos(int val, int pos) {
    Node* newNode = new Node();
    newNode->data = val;

    if (pos == 1) { // Insert at beginning
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete at beginning
void deleteAtBegin() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to delete at end
void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

// Function to delete at given position
void deleteAtPos(int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Function to display elements
void display() {
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}

int main() {
    int choice, val, pos;
    do {
        cout << "\n--- Linked List Menu ---"<<endl;
        cout << "1. Insert at Beginning"<<endl;
        cout << "2. Insert at End"<<endl;
        cout << "3. Insert at Position"<<endl;
        cout << "4. Delete at Beginning"<<endl;
        cout << "5. Delete at End"<<endl;
        cout << "6. Delete at Position"<<endl;
        cout << "7. Display"<<endl;;
        cout << "8. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                insertAtBegin(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                insertAtPos(val, pos);
                break;
            case 4:
                deleteAtBegin();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                deleteAtPos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                cout << "Exiting..."<<endl;
                break;
            default:
                cout << "Invalid choice!"<<endl;
        }
    } while (choice != 8);

    return 0;
}
