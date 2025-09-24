#include <bits/stdc++.h>
using namespace std;

//Array Queue 
const int MAX = 5;
int arrQ[MAX];
int arrFront = -1, arrRear = -1;

void arrEnqueue(int x) {
    if (arrRear == MAX - 1) {
        cout << "Array Queue full!"<<endl;
        return;
    }
    if (arrFront == -1) arrFront = 0;
    arrQ[++arrRear] = x;
    cout << "Inserted " << x <<endl;
}

void arrDequeue() {
    if (arrFront == -1 || arrFront > arrRear) {
        cout << "Array Queue empty!"<<endl;
        return;
    }
    cout << "Deleted " << arrQ[arrFront++] <<endl;
    if (arrFront > arrRear) arrFront = arrRear = -1;
}

void arrDisplay() {
    if (arrFront == -1) {
        cout << "Array Queue empty!"<<endl;
        return;
    }
    cout << "Array Queue: ";
    for (int i = arrFront; i <= arrRear; i++) cout << arrQ[i] << " ";
    cout <<endl;
}

// Linked List Queue 
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};
Node* lFront = nullptr;
Node* lRear = nullptr;

void llEnqueue(int x) {
    Node* tmp = new Node(x);
    if (!lFront) lFront = lRear = tmp;
    else {
        lRear->next = tmp;
        lRear = tmp;
    }
    cout << "Inserted " << x <<endl;
}

void llDequeue() {
    if (!lFront) {
        cout << "Linked Queue empty!"<<endl;
        return;
    }
    Node* tmp = lFront;
    cout << "Deleted " << lFront->data <<endl;
    lFront = lFront->next;
    delete tmp;
    if (!lFront) lRear = nullptr;
}

void llDisplay() {
    if (!lFront) {
        cout << "Linked Queue empty!"<<endl;
        return;
    }
    cout << "Linked Queue: ";
    for (Node* p = lFront; p; p = p->next) cout << p->data << " ";
    cout <<endl;
}

// Main Menu 
int main() {
    int impl, ch, val;
    while (true) {
        cout << "\n========== Queue Menu =========="<<endl;
        cout << "1. Array Queue"<<endl;;
        cout << "2. Linked List Queue"<<endl;
        cout << "3. Exit"<<endl;
        cout << "Choice: ";
        cin >> impl;

        if (impl == 3) break;

        while (true) {
            cout << "\n1. Insert\n2. Delete\n3. Display\n4. Back\n";
            cout << "Enter choice: ";
            cin >> ch;

            if (ch == 4) break;

            switch (ch) {
                case 1:
                    cout << "Enter value: "; cin >> val;
                    if (impl == 1) arrEnqueue(val);
                    else llEnqueue(val);
                    break;
                case 2:
                    if (impl == 1) arrDequeue();
                    else llDequeue();
                    break;
                case 3:
                    if (impl == 1) arrDisplay();
                    else llDisplay();
                    break;
                default:
                    cout << "Invalid!"<<endl;
            }
        }
    }
    cout << "Good-bye!"<<endl;
}
