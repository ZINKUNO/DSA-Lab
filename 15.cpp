#include <iostream>
using namespace std;

int queue[5];
int front = -1, rear = -1;

void enqueue()
{
    
    if (rear == 5 - 1)
    {
        cout << "Queue is full! Cannot insert." << endl;
        return;
    }
    int value;
    cout << "Enter value to insert: ";
    cin >> value;

    if (front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = value;
    cout << "Inserted: " << value << endl;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty! Cannot delete." << endl;
        return;
    }

    cout << "Deleted: " << queue[front] << endl;
    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main()
{
    int choice;

    cout << "Simple Queue Implementation" << endl;
    cout << "Size: " << 5 << endl
         << endl;

    while (true)
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
        cout << endl;
    }
}
