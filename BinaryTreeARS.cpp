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

void max(node *root){
    if(root->data != NULL){
        
    }
    int highest = 0;  // Initialize highest with a default value
    int leftH = 0;
    int rightH = 0;

    if (root->left != NULL) {
        leftH = root->left->data;
    }
    if (root->right != NULL) {
        rightH = root->right->data;
    }

    // Find the highest between left and right child values
    if (leftH > rightH) {
        highest = leftH;
    } else {
        highest = rightH;
    }

    cout << root->data << " ";

    if(highest != 0){
    cout << "Highest of left and right: " << highest << endl;  // Print the highest between left and right
    }
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

void InOrder(node *root) {
    if (root == NULL) {
        return;
    }

    InOrder(root->left);  // Recursively call left subtree

    cout << root->data << " ";  // Print the root data during in-order traversal

    InOrder(root->right);  // Recursively call right subtree
}


int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "Pre order" <<endl;
    PreOrder(root);
    cout << endl;

    cout << "In order" <<endl;
    InOrder(root);
    cout << endl;

    cout << "Post order" <<endl;
    PostOrder(root);
    cout << endl;

    return 0;
}