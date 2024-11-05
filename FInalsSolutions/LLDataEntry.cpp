#include <iostream>

using namespace std;

struct Node{
    Node * next;
    int data;
};

int main(){
    Node * n = NULL;
    Node * pHead = NULL;
    int data;

    while(true){
        cin >> data;
        if(data == -999){
            break;
        }
        n = new Node;
        n->data = data;
        n->next = NULL;

        if(pHead == NULL){
            pHead = n;
        }else {
            Node *temp = pHead;

            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next =  n;
        }
    }

    cout << "Linked List contents are: ";
    Node *current = pHead;

    while(current != NULL){
        cout << current->data << " ,";
        current = current->next;
    }

    cout << endl;

    while(pHead != NULL){
        current = pHead;
        pHead = pHead->next;
        delete current;
    }
    return 0;
}