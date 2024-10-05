#include <iostream>

using namespace std;

class Node{ friend class List; // gives List class access to private
    private:
    int nData;
    Node* pNext;
    Node* pPrev; 
    
    public:
    Node ( int data ) {
        nData = data; 
        pNext = NULL;
        pPrev = NULL; }
    int getData( ){ 
        return nData; 
    }     
};

class List{ 
    private:
    Node* pHead;
    Node* pTail;
    Node* createNode ( int data ) ;
    
    public: 
    List (){
        pHead = NULL;
        pTail = NULL;
    };
    ~List(){
    };
    void appendNode ( int value );
    void insertNode ( int value, Node *pAfter);
    bool isEmpty ( ); 
    void printList ( );
    void removeNode (Node *node); // Homework 

};

List::List ( ) {
    pHead=NULL;
    pTail=NULL;
};

List::~List ( ) {
    while ( !isEmpty ( ) ){ // keep on removing until the
    // head points to NULL
    removeNode( pHead );
    cout << "List deleted\n";
    }
};

Node* List::createNode ( int data ) { 
    //allocate memory for new node and 
    //intialize value to data 
    Node* pNode = new Node ( data ) ; 
    return pNode;
};

bool List::isEmpty ( ) { 
    return pHead == NULL;
};

void List::appendNode ( int value ) {
    Node* pNode = createNode ( value ) ;
    if ( isEmpty ( ) ) { // if list is empty 
    pHead = pNode; // make head point to pNode 
    pNode->pPrev = NULL; 
    }
};

int main(){
    List sampleList;
// Add items to linked list 
    for (int i = 0; i < 100; i++)
    sampleList.appendNode ( i ); //add node to list 
    //print the list
    sampleList.printList(); 
    system ("pause"); 
    return 0;
}