#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST class
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a new node in BST
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Wrapper function to insert a value
    void insert(int value) {
        root = insert(root, value);
    }

    // Find the longest path (height of the tree)
    int longestPath(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = longestPath(node->left);
        int rightHeight = longestPath(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    // Wrapper function to get longest path
    int getLongestPath() {
        return longestPath(root);
    }

    // Find the minimum value in BST
    int findMin(Node* node) {
        if (node == nullptr) return -1;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->data;
    }

    // Wrapper function to find min value
    int getMin() {
        return findMin(root);
    }

    // Swap left and right pointers of every node (Mirror)
    void mirror(Node* node) {
        if (node == nullptr) return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

    // Wrapper function to mirror the tree
    void mirrorTree() {
        mirror(root);
    }

    // Search for a value in BST
    bool search(Node* node, int value) {
        if (node == nullptr) return false;
        if (node->data == value) return true;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

    // Wrapper function for searching a value
    bool searchValue(int value) {
        return search(root, value);
    }

    // Inorder traversal (For debugging)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

// Main function
int main() {
    BST tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80}; // Given values
    for (int val : values) {
        tree.insert(val);
    }

    cout << "Binary Search Tree (Inorder Traversal): ";
    tree.display();

    // Insert a new node
    tree.insert(25);
    cout << "After inserting 25: ";
    tree.display();

    // Find the longest path
    cout << "Number of nodes in longest path from root: " << tree.getLongestPath() << endl;

    // Find the minimum value in BST
    cout << "Minimum data value found in tree: " << tree.getMin() << endl;

    // Mirror the BST
    tree.mirrorTree();
    cout << "BST after mirroring: ";
    tree.display();

    // Search for a value
    int searchKey = 40;
    cout << "Searching for " << searchKey << ": " << (tree.searchValue(searchKey) ? "Found" : "Not Found") << endl;

    return 0;
}

