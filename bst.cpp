#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Binary Tree Insert (Manual Insertion)
void insertBinaryTree(Node*& root, int val) {
    Node* newNode = new Node(val);
    if (!root) {
        root = newNode;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front(); q.pop();
        if (!temp->left) {
            temp->left = newNode;
            break;
        } else q.push(temp->left);
        
        if (!temp->right) {
            temp->right = newNode;
            break;
        } else q.push(temp->right);
    }
}

// Binary Search Tree Insert
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Iterative Inorder Traversal
void inorderIterative(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}
Node* cloneTree(Node* root) {
    if (!root) return nullptr;
    Node* clonedNode = new Node(root->data);
    clonedNode->left = cloneTree(root->left);
    clonedNode->right = cloneTree(root->right);
    return clonedNode;
}

// Mirror a Tree
Node* mirrorTree(Node* root) {
    if (!root) return nullptr;
    Node* mirroredNode = new Node(root->data);
    mirroredNode->left = mirrorTree(root->right);
    mirroredNode->right = mirrorTree(root->left);
    return mirroredNode;
}


// Iterative Preorder Traversal
void preorderIterative(Node* root) {
    if (!root) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* curr = st.top(); st.pop();
        cout << curr->data << " ";
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    cout << endl;
}

// Iterative Postorder Traversal (Two Stack Method)
void postorderIterative(Node* root) {
    if (!root) return;
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty()) {
        Node* curr = st1.top(); st1.pop();
        st2.push(curr);
        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
    cout << endl;
}

// Level Order Traversal
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

int main() {
    Node* binaryTree = nullptr;
    Node* bst = nullptr;
    int n, val;
    
    cout << "Enter the number of nodes for Binary Tree: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        insertBinaryTree(binaryTree, val);
    }
    
    cout << "Enter the number of nodes for BST: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        bst = insertBST(bst, val);
    }
    
    bool run = true;
    while (run) {
        cout << "\nMenu:\n1. Inorder Traversal\n2. Preorder Traversal\n3. Postorder Traversal\n4. Level Order Traversal\n5. Exit\nEnter choice: ";
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Binary Tree Inorder: "; inorderIterative(binaryTree);
                cout << "BST Inorder: "; inorderIterative(bst);
                break;
            case 2:
                cout << "Binary Tree Preorder: "; preorderIterative(binaryTree);
                cout << "BST Preorder: "; preorderIterative(bst);
                break;
            case 3:
                cout << "Binary Tree Postorder: "; postorderIterative(binaryTree);
                cout << "BST Postorder: "; postorderIterative(bst);
                break;
            case 4:
                cout << "Binary Tree Level Order: "; levelOrder(binaryTree);
                cout << "BST Level Order: "; levelOrder(bst);
                break;
            case 5:
                run = false;
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
