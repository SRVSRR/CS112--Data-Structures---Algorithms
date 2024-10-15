#include <iostream>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;

    node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

int findMax(node* root) {
    if (root == nullptr)
        return 0;
    int max;
    int maxVal = root->data;  // Start with root data


    int leftMax = findMax(root->left);  // Find max in left subtree
    int rightMax = findMax(root->right);  // Find max in right subtree

    /*
    maxVal is root
    Highest Lowest in left right side of the tree as maxleft wirh other side of branch as right max 
    */ 
    
    if(maxVal < leftMax){
        max = leftMax; 
    }else if(maxVal < rightMax){
        max = rightMax;
    }else {
        leftMax = findMax(root->left);  // Find max in left subtree
        rightMax = findMax(root->right);  // Find max in right subtree
    }

    return max;
}

void PreOrder(node *root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";

    PreOrder(root->left);

    PreOrder(root->right);
}

void PostOrder(node *root){
    if(root == NULL){
        return;
    }
    
    PostOrder(root->left);
        
    PostOrder(root->right);

    cout << root->data << " ";
}

void InOrder(node *root){
    if(root == NULL){
        return;
    }

    InOrder(root->left);

    cout << root->data << " ";

    InOrder(root->right);
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << "Pre order" <<endl;
    PreOrder(root);
    cout << endl;

    cout << "In order" <<endl;
    InOrder(root);
    cout << endl;

    cout << "Post order" <<endl;
    PostOrder(root);
    cout << endl;

    int highest = findMax( root);
    cout << highest;
}