#include <iostream>
#include <vector>
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
    void inorder(Node* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, result);
        result.push_back(node->data);
        inorder(node->right, result);
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
    // Public method to rebuild BST from a given traversal
    void rebuildFromTraversal(const vector<int>& traversal) {
        root = nullptr; // Clear the current tree
        for (int value : traversal) {
            insert(value);
        }
    }

    // Public method to get sorted values (In-order traversal)
    vector<int> getSortedOrder() {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};
int main() {
    BST tree;
    // Input Pre-order or Post-order traversal
    vector<int> inputTraversal = {50, 30, 20, 40, 70, 60, 80}; // Example: Pre-order traversal
    cout << "Input Pre-order traversal: ";
    for (int value : inputTraversal) {
        cout << value << " ";
    }
    cout << endl;
    // Rebuild BST from the given traversal
    tree.rebuildFromTraversal(inputTraversal);
    // Get and display sorted order
    vector<int> sortedOrder = tree.getSortedOrder();
    cout << "Sorted order (In-order traversal): ";
    for (int value : sortedOrder) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
