#include <iostream> 

using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

int main(){
    node *n1 = new node;
    node *n2 = new node;

    node *head;
    node *tail;
    head = n1;
    tail = n2;

    n2->data = 10;

    n1->next = n2;
    n1->prev = NULL;
    n2->prev = n1;
    n2->next = NULL;

    return 0;
}