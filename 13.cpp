#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;
const int MAX_SIZE = 1000;
int currentSize = 0;

void push(int val) {
    if (currentSize == MAX_SIZE) {
        cout << "Limit reached (" << MAX_SIZE << "). Cannot push.\n";
        return;
    }
    Node* n = new Node{val, top};
    top = n;
    ++currentSize;
    cout << val << " pushed\n";
}

void pop() {
    if (top == nullptr) {
        cout << "Underflow! Stack is empty.\n";
        return;
    }
    Node* tmp = top;
    cout << top->data << " popped\n";
    top = top->next;
    delete tmp;
    --currentSize;
}

int getTop() {
    if (top == nullptr) {
        cout << "Stack is empty.\n";
        return -1;
    }
    return top->data;
}

void display() {
    if (top == nullptr) {
        cout << "[empty]\n";
        return;
    }
    cout << "Stack (top->bottom): ";
    for (Node* cur = top; cur; cur = cur->next)
        cout << cur->data << ' ';
    cout << "\nCurrent size = " << currentSize << "/" << MAX_SIZE << '\n';
}


int main() {
    int choice;
    cout << "Linked-List Stack (max " << MAX_SIZE << " elements)\n";

    while (true) {
        cout << "\n1.Push  2.Pop  3.Top  4.Display  0.Exit\nChoice: ";
        if (!(cin >> choice)) break;

        if (choice == 0) {
            cout << "Exiting...\n";
            break;
        }

        switch (choice) {
            case 1: {
                int v;
                cout << "Value: ";
                cin >> v;
                push(v);
                break;
            }
            case 2:
                pop();
                break;
            case 3: {
                int t = getTop();
                if (t != -1) cout << "Current top = " << t << '\n';
                break;
            }
            case 4:
                display();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}