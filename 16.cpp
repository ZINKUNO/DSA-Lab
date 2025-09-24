#include <iostream>
using namespace std;

// Queue using Array 
class QueueArray {
    int *arr;
    int front, rear, capacity, size;

public:
    QueueArray(int c) {
        capacity = c;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~QueueArray() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow"<<endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow"<<endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

// Queue using Linked List 
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class QueueLL {
    Node *front, *rear;

public:
    QueueLL() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow"<<endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty"<<endl;
            return;
        }
        cout << "Queue: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main Menu 
int main() {
    int choice, implChoice;
    cout << "Choose Queue Implementation:\n";
    cout << "1. Array\n";
    cout << "2. Linked List\n";
    cout << "Enter choice: ";
    cin >> implChoice;

    if (implChoice == 1) {
        int capacity;
        cout << "Enter capacity of array queue: ";
        cin >> capacity;
        QueueArray q(capacity);

        do {
            cout << "\n--- Queue Menu (Array) ---\n";
            cout << "1. Enqueue\n2. Dequeue\n3. Get Front\n4. Display\n5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    int x;
                    cout << "Enter value: ";
                    cin >> x;
                    q.enqueue(x);
                    break;
                }
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    cout << "Front: " << q.getFront() << endl;
                    break;
                case 4:
                    q.display();
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 5);
    }
    else if (implChoice == 2) {
        QueueLL q;

        do {
            cout << "\n--- Queue Menu (Linked List) ---"<<endl;
            cout << "1. Enqueue\n2. Dequeue\n3. Get Front\n4. Display\n5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice) {
                case 1: {
                    int x;
                    cout << "Enter value: ";
                    cin >> x;
                    q.enqueue(x);
                    break;
                }
                case 2:
                    q.dequeue();
                    break;
                case 3:
                    cout << "Front: " << q.getFront() << endl;
                    break;
                case 4:
                    q.display();
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice!\n";
            }
        } while (choice != 5);
    }
    else {
        cout << "Invalid implementation choice!"<<endl;
    }

    return 0;
}
