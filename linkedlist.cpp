#include <iostream> 

using namespace std;

struct node {
    int data;
    node *next;
};

int main(){
    // node n <- inconsistent 
    // n.data when dealing with objects
    node *n;
    n = new node;

    node *n2 = new node;
    delete n2;
    n2 = NULL;

    node *n3 = new node;
    n->next = n3;
    n->next->next->data = 8;

    node *n4 = new node;
    n3->next->next->next = n4;
    n3->next->next->next->data = 2;

    node *n5 = new node;
    n4->next->next->next->next = n5;
    n4->next->next->next->next->data = 2;

    node *n6 = new node;
    n5->next->next->next->next->next = n5;
    n5->next->next->next->next->next->data = 2;

    return 0;
}