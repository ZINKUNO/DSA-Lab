#include <iostream>
using namespace std;

const int MAX = 1000;
int st[MAX];
int topA = -1;         

void pushA(int val) {
    if (topA == MAX - 1) {
        cout << "Overflow! Cannot push " << val << '\n';
        return;
    }
    st[++topA] = val;
    cout << val << " pushed (array)\n";
}

void popA() {
    if (topA == -1) {
        cout << "Underflow! Array stack is empty.\n";
        return;
    }
    cout << st[topA--] << " popped (array)\n";
}

int getTopA() {
    if (topA == -1) {
        cout << "Array stack is empty.\n";
        return -1;
    }
    return st[topA];
}

void displayA() {
    if (topA == -1) {
        cout << "[array] empty\n";
        return;
    }
    cout << "Array stack (top->bottom): ";
    for (int i = topA; i >= 0; --i) cout << st[i] << ' ';
    cout << '\n';
}

struct Node {
    int data;
    Node* next;
};
Node* topL = nullptr;   

void pushL(int val) {
    Node* n = new Node{val, topL};
    topL = n;
    cout << val << " pushed (list)\n";
}

void popL() {
    if (topL == nullptr) {
        cout << "Underflow! List stack is empty.\n";
        return;
    }
    Node* tmp = topL;
    cout << topL->data << " popped (list)\n";
    topL = topL->next;
    delete tmp;
}

int getTopL() {
    if (topL == nullptr) {
        cout << "List stack is empty.\n";
        return -1;
    }
    return topL->data;
}

void displayL() {
    if (topL == nullptr) {
        cout << "[list] empty\n";
        return;
    }
    cout << "List stack (top->bottom): ";
    for (Node* cur = topL; cur; cur = cur->next) cout << cur->data << ' ';
    cout << '\n';
}

void menuA() {                 
    int choice;
    cout << "\n=== ARRAY STACK ===\n";
    while (true) {
        cout << "\n1.Push  2.Pop  3.Top  4.Display  0.Back\nChoice: ";
        if (!(cin >> choice)) break;
        if (choice == 0) return;
        switch (choice) {
            case 1: { int v; cout << "Value: "; cin >> v; pushA(v); break; }
            case 2: popA(); break;
            case 3: { int t = getTopA(); if (t != -1) cout << "Top = " << t << '\n'; break; }
            case 4: displayA(); break;
            default: cout << "Invalid choice.\n";
        }
    }
}

void menuL() {                 
    int choice;
    cout << "\n=== LINKED-LIST STACK ===\n";
    while (true) {
        cout << "\n1.Push  2.Pop  3.Top  4.Display  0.Back\nChoice: ";
        if (!(cin >> choice)) break;
        if (choice == 0) return;
        switch (choice) {
            case 1: { int v; cout << "Value: "; cin >> v; pushL(v); break; }
            case 2: popL(); break;
            case 3: { int t = getTopL(); if (t != -1) cout << "Top = " << t << '\n'; break; }
            case 4: displayL(); break;
            default: cout << "Invalid choice.\n";
        }
    }
}

int main() {
    char which;
    cout << "Choose implementation:\nA - Array stack\nL - Linked-list stack\nX - Exit\nYour choice: ";
    while (cin >> which) {
        switch (toupper(which)) {
            case 'A': menuA(); break;
            case 'L': menuL(); break;
            case 'X': cout << "Good-bye!\n"; return 0;
            default : cout << "Invalid, try A / L / X: ";
        }
        cout << "\nChoose implementation (A/L/X): ";
    }
    return 0;
}