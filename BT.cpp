#include <iostream>
#include <iomanip> 
#include <queue>
using namespace std;


struct TreeNode {
    char data;                // Value of the node
    TreeNode* left;         // Pointer to the left child
    TreeNode* right;        // Pointer to the right child

    TreeNode(int value) : data(value), left(0), right(0) {}
};

// Function to display the binary tree
void displayTree(TreeNode* root, int space = 0, int height = 10) {
    if (root == 0)
    return;

    space += height; // Increase distance between levels

    // Process left child first
    displayTree(root->left, space);

    // Print current node after space
    cout << endl;
    for (int i = height; i < space; i++){
        cout << " ";
    }
    cout << root->data << "\n";

    // Process right child
    displayTree(root->right, space);
}

// In-order traversal (Left, Root, Right)
void inOrder(TreeNode* node) {
    if (node == 0) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

// Pre-order traversal (Root, Left, Right)
void preOrder(TreeNode* node) {
    if (node == 0) return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// Post-order traversal (Left, Right, Root)
void postOrder(TreeNode* node) {
    if (node == 0) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main() {
    // Creating a simple binary tree
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('E');
    root->left->left = new TreeNode('C');
    root->left->right = new TreeNode('D');
    root->right->left = new TreeNode('F');
    root->right->right = new TreeNode('G');
    root->right->right->left = new TreeNode('H');

    // Display the tree
    cout << "Binary Tree Structure:\n";
    displayTree(root);

    // Traversals
    cout << "\nIn-order Traversal: ";
    inOrder(root);
    cout << "\nPre-order Traversal: ";
    preOrder(root);
    cout << "\nPost-order Traversal: ";
    postOrder(root);
    cout << endl;

    

    return 0;
}

