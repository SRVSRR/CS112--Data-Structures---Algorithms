#include <iostream> 

using namespace std;

struct node {
    int data;
    node *next = NULL;
    node *prev = NULL;
};

int main(){
    node *n = new node;

    n->next  = new node;
    n->next->data  = 5;

    n->next->next  = new node;
    n->next->next->prev = n->next;
    n->next->next->data  = 8;

    return 0;
}