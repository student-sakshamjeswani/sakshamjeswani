//Here's the implementation of a Binary Search Tree (BST) in C++. 
#include <iostream>
using namespace std;
// Definition of a Node in the Binary Search Tree

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
// Binary Search Tree Class
class BST {
private:
    Node* root;
    // Helper function to insert a node recursively
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }
    // Helper function for in-order traversal
    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    // Helper function to search for a value
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }
public:
    // Constructor
    BST() {
        root = nullptr;
    }
    // Public method to insert a value
    void insert(int value) {
        root = insert(root, value);
    }
    void inorder() {
        inorder(root);
        cout << endl;
    }
    bool search(int value) {
        return search(root, value);
    }
};
int main() {
    BST tree;
    // Insert nodes into the BST
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    // Perform in-order traversal
    cout << "In-order traversal: ";
    tree.inorder();
    // Search for values in the BST
    int value;
    cout << "Enter a value to search: ";
    cin >> value;
    if (tree.search(value)) {
        cout << value << " is found in the BST." << endl;
    } else {
        cout << value << " is not found in the BST." << endl;
    }
    return 0;
}
