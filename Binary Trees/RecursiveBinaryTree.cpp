#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Recursive Preorder Traversal
void preorder(Node* root) {
    if (root == nullptr)
        return;
    
    // Visit the root node
    cout << root->data << " ";
    
    // Traverse the left subtree
    preorder(root->left);
    
    // Traverse the right subtree
    preorder(root->right);
}

// Recursive Postorder Traversal
void Postorder(Node* root) {
    if (root == nullptr)
        return;
    
    // Visit the root node
    cout << root->data << " ";
    
    // Traverse the right subtree
    preorder(root->right);

    // Traverse the left subtree
    preorder(root->left);
}

void InOrder(Node* root) {
    if (root == nullptr){
        return;
    }
    // Traverse the left subtree
    preorder(root->left);

    // Visit the root node
    cout << root->data << " ";

    // Traverse the right subtree
    preorder(root->right);
}

int main() {
    // Creating a simple binary tree
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->left = new Node('F');
    root->right->right = new Node('G');
    root->left->left->left = new Node('J');
    root->left->left->right = new Node('K');
    root->left->right->left = new Node('H');
    root->left->right->right = new Node('I');
    root->right->left->left = new Node('L');
    root->right->left->right = new Node('M');
    root->right->right->left = new Node('N');
    root->right->right->right = new Node('O');
    
    cout << "Preorder traversal (recursive): ";
    preorder(root);
    cout << endl;
    cout << "Postorder traversal (recursive): ";
    Postorder(root);
    cout << endl;
    cout << "Inorder traversal (recursive): ";
    InOrder(root);
    
    return 0;
}
