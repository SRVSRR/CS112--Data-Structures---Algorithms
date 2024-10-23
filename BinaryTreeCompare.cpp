/*
**Question:**
Given a binary tree, write a function to check if it is a valid binary search tree (BST). A BST is defined as follows:

- The left subtree of a node contains only nodes with values **less than** the node's value.
- The right subtree of a node contains only nodes with values **greater than** the node's value.
- Both the left and right subtrees must also be binary search trees.

**Function Signature:**

bool isValidBST(TreeNode* root);

**Example:**
Input:
    2
   / \
  1   3

Output: True

Input:
    5
   / \
  1   4
     / \
    3   6

Output: False
Explanation: The root node's value is 5 but the right child's subtree contains a value 3, which is not greater than 5.

**Constraints:**
- The number of nodes in the tree is in the range `[1, 10^4]`.
- The value of each node is in the range `[-10^4, 10^4]`.

---

bool isValidBST(TreeNode* root) {
    // Your code here
}
*/


#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string>

using namespace std;

template <class dataType>
class BinaryTree {
    public:
        BinaryTree( );
        bool isLeaf ();
        dataType getData();
        void insert (const dataType & d);
        BinaryTree * left();
        BinaryTree * right();
        void makeLeft (BinaryTree * T1);
        void makeRight (BinaryTree *T1);
    private:
        dataType treeData;
        BinaryTree * leftTree;
        BinaryTree * rightTree;
};

template <class dataType>   //constructor
BinaryTree<dataType>::BinaryTree()
{
    leftTree = NULL;
    rightTree = NULL;
}

template <class dataType>
bool BinaryTree<dataType>::isLeaf()
{
    return ((this->leftTree == NULL) && (this->rightTree == NULL));
}

template <class dataType>
dataType BinaryTree<dataType>::getData()
{
    return treeData;
}

template <class dataType>
void BinaryTree <dataType>::insert (const dataType & d)
{
    treeData = d;
}

template <class dataType>
BinaryTree <dataType> * BinaryTree<dataType> :: left()
{
    return leftTree;
}

template <class dataType>
BinaryTree <dataType> * BinaryTree<dataType> :: right()
{
    return rightTree;
}

template <class dataType>
void BinaryTree <dataType> :: makeLeft (BinaryTree * T1)
{
    leftTree = T1;
}

template <class dataType>
void BinaryTree <dataType> :: makeRight (BinaryTree * T1)
{
    rightTree = T1;
}

template <class dataType>
void printLeaves (BinaryTree <dataType> * bt)
{
    if (bt != NULL)
    {
        if (bt->isLeaf())
            cout << bt->getData() <<"\t";
        else
        {
            printLeaves(bt->left());
            printLeaves(bt->right());
        }
    }
}

template <class dataType>
void printBranches (BinaryTree <dataType> * bt)
{
    if (bt != NULL && !bt->isLeaf())
    {
        cout << bt->getData() <<"\t";
        printBranches(bt->left());
        printBranches(bt->right());
    }
}

template <class dataType>
void printRoot (BinaryTree <dataType> * bt)
{
    if (bt != NULL){
        cout << "Root: " << bt->getData() << endl;
    }
}

template <class dataType>
bool isValidBSTHelper(BinaryTree<dataType>* bt, dataType min, dataType max) {
    if (bt == nullptr) {
        return true;  // An empty tree is valid
    }

    dataType root = bt->getData();

    // Check if the current node violates the BST property
    if (root <= min || root >= max) {
        return false;
    }

    // Recursively check left and right subtrees with updated boundaries
    return isValidBSTHelper(bt->left(), min, root) && isValidBSTHelper(bt->right(), root, max);
}

template <class dataType>
int isValid(BinaryTree<dataType>* bt) {
    if (isValidBSTHelper(bt, std::numeric_limits<dataType>::min(), std::numeric_limits<dataType>::max())) {
        return 1;  // Return 1 for a valid BST
    } else {
        return 0;  // Return 0 for an invalid BST
    }
}

int main()
{
    BinaryTree <char> * root = new BinaryTree <char>();
    root->insert('A');
    
    root->makeLeft(new BinaryTree <char>);
    root->left()->insert('B');
    root->makeRight(new BinaryTree <char>);
    root->right()->insert('C');
    
    root->left()->makeLeft(new BinaryTree <char>);
    root->left()->left()->insert('D');
    root->left()->makeRight(new BinaryTree <char>);
    root->left()->right()->insert('E');
    root->left()->right()->makeRight(new BinaryTree <char>);
    root->left()->right()->right()->insert('H');
    
    root->right()->makeRight(new BinaryTree <char>);
    root->right()->right()->insert('F');
    
    root->left()->left()->makeLeft(new BinaryTree <char>);
    root->left()->left()->left()->insert('G');

    bool check = true; 

    /* binary tree:
                A
              /   \
             B     C
            / \     \
           D   E     F
          /     \
         G       H
    */

    // print the root
    printRoot(root);

    // print branches (non-leaf nodes except root)
    cout << "Branches: ";
    printBranches(root);
    cout << endl;

    // print leaves
    cout << "Leaves: ";
    printLeaves(root);
    cout << endl;
    
    cout << "Valid: ";
    cout << isValid(root);
    
    system("PAUSE");
    return 0;
}
