
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
    if (bt != NULL)
        cout << "Root: " << bt->getData() << endl;
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
    
    system("PAUSE");
    return 0;
}
