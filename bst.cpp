#include <bits/stdc++.h>
#include <stack>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node() {
        left = nullptr;
        right = nullptr;
        data = 0;
    }
    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

void insert(node*& root, int val) {
    node* p = new node(val);
    if (root == nullptr) {
        root = p;
    }
    else {
        node* temp = root;
        while (true) {
            std::cout << "1.insert  left of " << temp->data << endl;
            std::cout << "2.insert  right of " << temp->data << endl;
            int c;
            cout << "Enter your choice: ";
            std::cin >> c;

            if (c == 1) {
                if (temp->left == nullptr) {
                    temp->left = p;
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else if (c == 2) {
                if (temp->right == nullptr) {
                    temp->right = p;
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
            else {
                cout << " Please choose either 1 or 2." << endl;
            }
        }
    }
}

void inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
   
}

void postorder(node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    
}

void preorder(node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    
}

void iterativePreorder(node* root) {
    if (root == nullptr) return;

    stack<node*> st;
    st.push(root);

    while (!st.empty()) {
        node* p = st.top();
        st.pop();
        cout << p->data << " ";

        // Push right child first so that left is processed first
        if (p->right) st.push(p->right);
        if (p->left) st.push(p->left);
    }
}


void iterativeInorder(node* root) {
    if (root == nullptr) return;

    stack<node*> st;
    node* curr = root;

    while (curr != nullptr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}


void iterativePostorder(node* root) {
    if (root == nullptr) return;

    stack<node*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        node* p = st1.top();
        st1.pop();
        st2.push(p);

        if (p->left) st1.push(p->left);
        if (p->right) st1.push(p->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void levelorder(node* root) {
    queue<node*> q;
    if (root != nullptr) {
        q.push(root);
        while (!q.empty()) {
            node* y = q.front();
            q.pop();
            cout << y->data << " ";
            if (y->left != nullptr) {
                q.push(y->left);
            }
            if (y->right != nullptr) {
                q.push(y->right);
            }
        }
    }
  
}
node* findMin(node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
node* deleteNode(node* root, int key) {
    if (root == nullptr) return root;

    node* parent = nullptr;
    node* curr = root;

    // Step 1: Find the node to delete
    while (curr && curr->data != key) {
        parent = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == nullptr) return root; // Node not found

    // Step 2: Handle cases

    // Case 1: Node has no child (Leaf node)
    if (!curr->left && !curr->right) {
        if (curr == root) return nullptr; // If root is the only node
        if (parent->left == curr) parent->left = nullptr;
        else parent->right = nullptr;
        delete curr;
    }

    // Case 2: Node has only one child
    else if (!curr->left || !curr->right) {
        node* child = (curr->left) ? curr->left : curr->right;

        if (curr == root) return child; // If root node is deleted, return new root
        if (parent->left == curr) parent->left = child;
        else parent->right = child;

        delete curr;
    }

    // Case 3: Node has two children
    else {
        node* successor = findMin(curr->right);
        int successorData = successor->data;
        root = deleteNode(root, successorData); // Delete inorder successor
        curr->data = successorData; // Replace with inorder successor's data
    }

    return root;
}


node* clone(node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    node* p1 = new node(root->data);
    p1->left = clone(root->left);
    p1->right = clone(root->right);
    return p1;
}

bool equal(node* root1, node* root2){
    bool a1;
    bool a2;
    bool a3;
    if(root1==nullptr&&root2==nullptr){
        return true;
    }
    if(root1==nullptr||root2==nullptr){
        return false;
    }
    
    else{
        a1=root1->data==root2->data;
        a2=equal(root1->left,root2->left);
        a3=equal(root1->right,root2->right);
    }
    if(a1==true&&a2==true&a3==true){
        return true;
    }
    else{
        return false;
    }
}

node* mirror(node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    node* p1 = new node(root->data);
    p1->left = mirror(root->right);
    p1->right = mirror(root->left);
    return p1;
}

void bst(node*& root, int val) {
    if (root == nullptr) {
        root = new node(val);
        return;
    }
    if (val < root->data){
        if(root->left==nullptr){
                node* p=new node(val);
                root->left=p;
                return;
        }
        bst(root->left,val);
    }
    else{
        if(root->right==nullptr){
                node* p1=new node(val);
                root->right=p1;
                return;
        }
       bst(root->right,val);
    }
}

int height(node* root) {
    if (root == nullptr){
        return 0;
    }
    int leftht = height(root->left);
    int rightht = height(root->right);
    return max(leftht, rightht) + 1;
}

bool searchbst(node* root, int val) {
    node* temp = root;
    while (temp != nullptr) {
        if (temp->data == val) {
            return true;
        }
        else if (temp->data > val) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return false;
}


int main() {
    node* root1 = nullptr;
    node* root2 = nullptr;
    int n;
    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter node value: ";
        cin >> value;
        insert(root1, value);
    }

    bool m = true;
    while (m) {
        const char* str = "          Menu\n\
                        0.  Create Binary Tree\n\
                        1.  Preorder (Recursive & Non-Recursive)\n\
                        2.  Postorder (Recursive & Non-Recursive)\n\
                        3.  Inorder (Recursive & Non-Recursive)\n\
                        4.  Level Order\n\
                        5.  Make a clone\n\
                        6.  Check if two trees are equal\n\
                        7.  Create mirror image\n\
                        8.  Create Binary Search Tree\n\
                        9.  Delete node from BST\n\
                        10. Construct BST from preorder & postorder\n\
                        11. Find height of tree\n\
                        12. Search in BST";
        int ch;
        std::cout << str;
        std::cout << "\nEnter your choice : ";
        std::cin >> ch;

        switch (ch) {
            case 1:
                cout << "Preorder traversal: ";
                preorder(root1);
                  cout << "Preorder traversal iterative: ";
                iterativePreorder(root1);
                 cout<<endl;
                break;
            case 2:
                cout << "Postorder traversal: ";
                postorder(root1);
                  cout << "Postorder traversal iterative: ";
                iterativePostorder(root1);
                 cout<<endl;
                break;
            case 3:
                cout << "Inorder traversal recursive: ";
                inorder(root1);
                 cout << "Inorder traversal iterative: ";
                iterativeInorder(root1);
                 cout<<endl;
                break;
            case 4:
                cout << "Level order traversal: ";
                levelorder(root1);
                cout<<endl;
                break;
            case 5:{
                cout<<"Making a Clone "<<endl;
                node* p=clone(root1);
                cout<<"clone tree:";
                inorder(p);
                break;}
            case 6:{
               
               bool m= equal(root1,root2);
               if (m)
               {
                cout<<"they are equal"<<endl;
               }else{
                cout<<"they are not equal"<<endl;
               }
               
                break;}
            case 7:{
                cout<<"Creating a Mirror image";
                node* k=mirror(root1);
                 cout<<" Mirror image tree:";
                inorder(k);

                break;}
            case 8:{
                cout<<"Creating a Binary Search Tree";
                cout<<"Enter Number of Nodes";
                int v;
                cin>>v;
                for(int i=0;i<v;i++){
                    int r;
                    cout<<"Enter Node "<<i+1<<" : ";
                    cin>>r;
                    bst(root2,r);
                }
                break;}
            case 9:{
                int l;
                cout<<"enter number to delete"<<endl;
                cin>>l;
                deleteNode(root2,l);
                break;
            }
            case 11:{
                cout<<"Calculating height of tree";
                int h1=height(root1);
                cout<<"Heght of tree is "<<h1;
                break;
            }
            case 12:{
                cout<<"Search is BST";
                int v1;
                cout<<"Enter value to be searched : ";
                cin>>v1;
                bool ans=searchbst(root2,v1);
                if(ans==true){
                    cout<<"Element Found";
                }
                else{
                    cout<<"Element absent";
                }
                break;}
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cout << "you want to Continue ? ";
        string st;
        cin >> st;
        if (st != "Y" && st != "y") {
            m = false;
        }
    }
    return 0;
}
