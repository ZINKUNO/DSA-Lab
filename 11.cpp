#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    Student() {}  

    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }

    void display() {
        cout << "[RollNo: " << rollNo 
             << ", Name: " << name 
             << ", Marks: " << marks << "]";
    }
};

struct Node {
    Student data;   
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;  

// Insert at beginning
void insertAtBegin(Student s) {
    Node* newNode = new Node();
    newNode->data = s;
    newNode->next = head;
    head = newNode;

    if (tail == NULL) 
        tail = newNode;
}

// Insert at end 
void insertAtEnd(Student s) {
    Node* newNode = new Node();
    newNode->data = s;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert at position
void insertAtPos(Student s, int pos) {
    Node* newNode = new Node();
    newNode->data = s;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        if (tail == NULL) tail = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Position out of range"<<endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (temp == tail) 
        tail = newNode;
}

// Delete at beginning
void deleteAtBegin() {
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == NULL) tail = NULL; 
    delete temp;
}

// Delete at end using tail
void deleteAtEnd() {
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != tail) // stop at second last node
        temp = temp->next;
    delete tail;
    tail = temp;
    tail->next = NULL;
}

// Delete at given position
void deleteAtPos(int pos) {
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
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

    if (del == tail) // update tail if last node deleted
        tail = temp;

    delete del;
}

// Display
void display() {
    if (head == NULL) {
        cout << "List is empty"<<endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        temp->data.display();
        cout << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, rollNo, pos;
    string name;
    float marks;

    do {
        cout << "\n--- Linked List Menu ---"<<endl;
        cout << "1. Insert at Beginning"<<endl;
        cout << "2. Insert at End"<<endl;
        cout << "3. Insert at Position"<<endl;
        cout << "4. Delete at Beginning"<<endl;
        cout << "5. Delete at End"<<endl;
        cout << "6. Delete at Position"<<endl;
        cout << "7. Display"<<endl;
        cout << "8. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll No, Name, Marks: ";
                cin >> rollNo >> name >> marks;
                insertAtBegin(Student(rollNo, name, marks));
                break;
            case 2:
                cout << "Enter Roll No, Name, Marks: ";
                cin >> rollNo >> name >> marks;
                insertAtEnd(Student(rollNo, name, marks));
                break;
            case 3:
                cout << "Enter Roll No, Name, Marks and Position: ";
                cin >> rollNo >> name >> marks >> pos;
                insertAtPos(Student(rollNo, name, marks), pos);
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
