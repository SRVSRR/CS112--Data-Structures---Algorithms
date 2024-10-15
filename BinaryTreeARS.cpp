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

}