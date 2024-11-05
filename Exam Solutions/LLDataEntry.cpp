#include <iostream>

using namespace std;

struct Node{
    Node * next;
    int data;
};

Node *reverse(Node *head){
    Node *prev = NULL;

    while(head != NULL){
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

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

    pHead = reverse(pHead);

    Node *current2 = pHead;

    while(current2 != NULL){
        cout << current2->data << " ,";
        current2 = current2->next;
    }

    cout << endl;

    while(pHead != NULL){
        current = pHead;
        pHead = pHead->next;
        delete current;
    }
    return 0;
}