#include <iostream>

using namespace std;

template <class dataType>
class BinaryTreeNode {
public:
    BinaryTreeNode() : leftTreeNode(nullptr), rightTreeNode(nullptr) {}

    bool isLeaf() {
        return leftTreeNode == nullptr && rightTreeNode == nullptr;
    }

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

int main() {
    BinaryTreeNode<char>* root = new BinaryTreeNode<char>();
    root->setData('A');

    BinaryTreeNode<char>* LB = new BinaryTreeNode<char>();
    LB->setData('B');
    root->setLeft(LB);

    root->setRight(new BinaryTreeNode<char>());
    root->getRight()->setData('C');

    if (root->getLeft() && root->getLeft()->getLeft()) {
        cout << root->getLeft()->getLeft()->getData();
    } else {
        cout << "No left child for B.";
    }

    return 0;
}
