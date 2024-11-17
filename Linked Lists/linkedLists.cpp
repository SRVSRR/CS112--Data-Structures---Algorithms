#include <iostream> 

using namespace std;

struct node {
    public:
        int data;
        node *next;
};

class stack {
    public:
        node *head;
        void push(node *node)
        {
            if(head != NULL){
                head->next = node;
            }
            head = node;
        }
        void pop(node *node){
            if(head ){
                head->next = NULL;
            }
            head = NULL;
        }
};

int main(){
    node *n = new node;
    n->data  = 5;
    n->next  = NULL;

    node *topnode = new node;
    topnode->data = 2;
    topnode->next = NULL;


    node *n = new node;
    n->data  = 5;
    n->next  = NULL;

    return 0;
}