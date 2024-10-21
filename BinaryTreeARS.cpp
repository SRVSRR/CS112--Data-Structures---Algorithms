#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        left = NULL;
        right = NULL;
        this->data = data;
    }

    Node *getLeft()
    {
        return left;
    }

    Node *getRight()
    {
        return right;
    }
};

class Tree
{
public:
    Node *root;

    int getMax(Node *node, int max)
    {
        if (node->data > max)
        {
            max = node->data;
        }

        if (node->left != NULL)
        {
            max = getMax(node->left, max);
        }

        if (node->right != NULL)
        {
            max = getMax(node->right, max);
        }

        return max;
    }
};

int main()
{
    Tree *tree = new Tree;
    Node *root = new Node(1);
    Node *left = new Node(2);
    Node *right = new Node(3);

    tree->root = root;
    root->left = left;
    root->right = right;

    cout << "Max: " << tree->getMax(root, 0) << endl;

    delete tree;

    return 0;
}