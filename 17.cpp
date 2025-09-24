#include <iostream>

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Helper function to insert a node (recursive)
    Node* insertHelper(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertHelper(node->left, val);
        } else if (val > node->data) {
            node->right = insertHelper(node->right, val);
        }
        // If val == node->data, do nothing (no duplicates)
        return node;
    }

    // Helper function to find the inorder successor (min in right subtree)
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to delete a node (recursive)
    Node* deleteHelper(Node* node, int val) {
        if (node == nullptr) {
            return node;
        }
        if (val < node->data) {
            node->left = deleteHelper(node->left, val);
        } else if (val > node->data) {
            node->right = deleteHelper(node->right, val);
        } else {
            // Node to delete found
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Node has two children: Get inorder successor
            Node* temp = minValueNode(node->right);
            node->data = temp->data;  // Copy successor's data
            node->right = deleteHelper(node->right, temp->data);  // Delete successor
        }
        return node;
    }

    // Helper function for inorder traversal (print sorted order)
    void inorderHelper(Node* node) {
        if (node != nullptr) {
            inorderHelper(node->left);
            std::cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Insert a value
    void insert(int val) {
        root = insertHelper(root, val);
        std::cout << "Inserted: " << val << std::endl;
    }

    // Delete a value
    void deleteNode(int val) {
        root = deleteHelper(root, val);
        std::cout << "Deleted: " << val << std::endl;
    }

    // Print inorder traversal
    void inorder() {
        std::cout << "Inorder traversal: ";
        inorderHelper(root);
        std::cout << std::endl;
    }

    // Destructor to free memory (post-order deletion)
    ~BST() {
        // Simple recursive deletion (could be optimized)
        if (root != nullptr) {
            deleteHelper(root, root->data);  // This will delete all nodes
        }
    }
};

// Example usage in main
int main() {
    BST tree;

    // Insert nodes
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.inorder();  // Output: 20 30 40 50 60 70 80

    // Delete nodes
    tree.deleteNode(20);  // Leaf node
    tree.inorder();       // Output: 30 40 50 60 70 80

    tree.deleteNode(30);  // Node with one child
    tree.inorder();       // Output: 40 50 60 70 80

    tree.deleteNode(50);  // Node with two children
    tree.inorder();       // Output: 40 60 70 80

    return 0;
}