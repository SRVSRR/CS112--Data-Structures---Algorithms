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

// Inorder Traversal (Left, Root, Right)
template <class dataType>
void inorderTraversal(BinaryTreeNode<dataType>* node) {
    if (node == nullptr) return;
    
    inorderTraversal(node->getLeft());
    cout << node->getData() << " ";
    inorderTraversal(node->getRight());
}

// Preorder Traversal (Root, Left, Right)
template <class dataType>
void preorderTraversal(BinaryTreeNode<dataType>* node) {
    if (node == nullptr) return;
    
    cout << node->getData() << " ";
    preorderTraversal(node->getLeft());
    preorderTraversal(node->getRight());
}

// Postorder Traversal (Left, Right, Root)
template <class dataType>
void postorderTraversal(BinaryTreeNode<dataType>* node) {
    if (node == nullptr) return;
    
    postorderTraversal(node->getLeft());
    postorderTraversal(node->getRight());
    cout << node->getData() << " ";
}

int main() {
    // Creating a binary tree
    BinaryTreeNode<char>* root = new BinaryTreeNode<char>();
    root->setData('A');

    BinaryTreeNode<char>* nodeB = new BinaryTreeNode<char>();
    nodeB->setData('B');
    root->setLeft(nodeB);

    BinaryTreeNode<char>* nodeC = new BinaryTreeNode<char>();
    nodeC->setData('C');
    root->setRight(nodeC);

    BinaryTreeNode<char>* nodeD = new BinaryTreeNode<char>();
    nodeD->setData('D');
    nodeB->setLeft(nodeD);

    BinaryTreeNode<char>* nodeE = new BinaryTreeNode<char>();
    nodeE->setData('E');
    nodeB->setRight(nodeE);

    BinaryTreeNode<char>* nodeF = new BinaryTreeNode<char>();
    nodeF->setData('F');
    nodeC->setLeft(nodeF);

    BinaryTreeNode<char>* nodeG = new BinaryTreeNode<char>();
    nodeG->setData('G');
    nodeC->setRight(nodeG);

    // Traversals
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
