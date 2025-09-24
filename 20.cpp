
//implement binary tree and   transveral using preorder,postorder and inorder 
//10, 5, 15, 3, 7, 12, 18
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int v) : key(v), left(nullptr), right(nullptr) {}
};

// traversals 
void preorderRec(Node* root) {//root,left,right
    if (!root) return;
    cout << root->key << " ";
    preorderRec(root->left);
    preorderRec(root->right);
}

void inorderRec(Node* root) {//left root right
    if (!root) return;
    inorderRec(root->left);
    cout << root->key << " ";
    inorderRec(root->right);
}

void postorderRec(Node* root) {//left right and roor 
    if (!root) return;
    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->key << " ";
}

// insert into binary tree 
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->key)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

/* ---------- delete entire tree ---------- */
void destroy(Node* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

/* ---------- driver ---------- */
int main() {
    Node* root = nullptr;
    int choice, val;

    while (true) {
        cout << "\nMenu:"<<endl;
        cout << "1. Insert node"<<endl;
        cout << "2. Preorder Traversal"<<endl;
        cout << "3. Inorder Traversal"<<endl;
        cout << "4. Postorder Traversal"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;

            case 2:
                cout << "Preorder: ";
                preorderRec(root);
                cout <<endl;
                break;

            case 3:
                cout << "Inorder: ";
                inorderRec(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder: ";
                postorderRec(root);
                cout <<endl;
                break;

            case 0:
                destroy(root);
                return 0;

            default:
                cout << "Invalid choice!"<<endl;
        }
    }
}
