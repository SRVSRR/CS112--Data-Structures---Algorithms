#include <iostream>

using namespace std;

template <class dataType>
class BinaryTreeNode {
public:
    BinaryTreeNode() : leftTreeNode(nullptr), rightTreeNode(nullptr) {}

    dataType getData() {
        return treeNodeData;
    }

    void setData(const dataType& d) {
        treeNodeData = d;
    }

    BinaryTreeNode* getLeft() {
        return leftTreeNode;
    }

    BinaryTreeNode* getRight() {
        return rightTreeNode;
    }

    void setLeft(BinaryTreeNode* T1) {
        leftTreeNode = T1;
    }

    void setRight(BinaryTreeNode* T1) {
        rightTreeNode = T1;
    }

private:
    dataType treeNodeData;
    BinaryTreeNode* leftTreeNode;
    BinaryTreeNode* rightTreeNode;
};

// Insert a node into the Binary Search Tree
template <class dataType>
BinaryTreeNode<dataType>* insertBST(BinaryTreeNode<dataType>* node, dataType value) {
    if (node == nullptr) {
        node = new BinaryTreeNode<dataType>();
        node->setData(value);
        return node;
    }

    if (value < node->getData()) {
        node->setLeft(insertBST(node->getLeft(), value));
    } else if (value > node->getData()) {
        node->setRight(insertBST(node->getRight(), value));
    }

    return node;
}

// Inorder Traversal (Left, Root, Right) - For Alphabetical Order
template <class dataType>
void inorderTraversal(BinaryTreeNode<dataType>* node) {
    if (node == nullptr) return;
    
    inorderTraversal(node->getLeft());
    cout << node->getData() << " ";
    inorderTraversal(node->getRight());
}

int main() {
    BinaryTreeNode<char>* root = nullptr;

    // Insert nodes into the BST
    root = insertBST(root, 'F');
    root = insertBST(root, 'D');
    root = insertBST(root, 'J');
    root = insertBST(root, 'B');
    root = insertBST(root, 'E');
    root = insertBST(root, 'G');
    root = insertBST(root, 'K');
    root = insertBST(root, 'A');
    root = insertBST(root, 'C');
    root = insertBST(root, 'I');

    // Perform inorder traversal to print in alphabetical order
    cout << "Inorder Traversal (Alphabetical Order): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
/*
         F
       /   \
      D     J
     / \   / \
    B   E G   K
   / \     \
  A   C     I
*/
