#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int v) : key(v), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int value)
{
    if (root == nullptr)
        return new Node(value);
    if (value < root->key)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

// Display BST using inorder traversal
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

Node *deleteNode(Node *root, int value)
{
    if (!root)
        return nullptr;

    if (value < root->key)
        root->left = deleteNode(root->left, value);
    else if (value > root->key)
        root->right = deleteNode(root->right, value);
    else
    {
        // 0 or 1 child
        if (!root->left || !root->right)
        {
            Node *tmp = root->left ? root->left : root->right;
            delete root;
            return tmp;
        }

        // 2 children → find inorder successor
        Node *succParent = root;
        Node *succ = root->right;
        while (succ->left)
        {
            succParent = succ;
            succ = succ->left;
        }

        root->key = succ->key;

        if (succParent == root)
            succParent->right = succ->right;
        else
            succParent->left = succ->right;
        delete succ;
    }
    return root;
}

int main()
{
    Node *root = nullptr;
    int choice;
    do
    {
        cout << "\n1. Insert node\n2. Delete node\n3. Display BST (Inorder)\n0. Exit\nChoice: ";
        if (!(cin >> choice))
            break;
        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        }
        case 2:
        {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            cout << "Deleted " << value << '\n';
            break;
        }
        case 3:
        {
            cout << "Inorder traversal: ";
            inorder(root);
            cout << "\n";
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
