#include <iostream> 

using namespace std;

struct node {
    int data;
    node *next;
};

int main(){
    // node n <- inconsistent 
    // n.data when dealing with objects
    node *n = new node;

    n->next  = new node;

    n->next->next  = new node;

    n->next->next->next  = new node;

    n->next->next->next->next  = new node;

    n->next->next->next->next->next  = new node;

    return 0;
}