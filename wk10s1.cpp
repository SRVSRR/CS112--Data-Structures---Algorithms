#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

struct Student {
   string Id;
   double marks;
   char grade;
};

struct NODE {
   NODE *pNext;
   NODE *pPrev;
   int nData;
};

//declare head and tail of list
//originally the list is empty
NODE *pHead=NULL, *pTail=NULL;

void AppendNode(NODE *pNode);
void InsertNode(NODE *pNode, NODE *pAfter);
void RemoveNode(NODE *pNode);
void DeleteAllNodes( );
void discard_line(ifstream &in);

int main( )
{
   NODE *pNode;
   for (int i = 0; i < 10; i++){
        pNode = new NODE;    //allocate
	                        // memory for each node and make
                            // pointer point to the
                            //dynamically allocated memory
    	pNode->nData = i;  //put some data in the node
        AppendNode(pNode); //add node to list
    }

    // Now display each item in list
   for(pNode = pHead; pNode != NULL; pNode = pNode->pNext){
      cout<<pNode->nData<<endl;
   }

   DeleteAllNodes();

    cout<<"Displaying afgter delete"<<endl;
   for(pNode = pHead; pNode != NULL; pNode = pNode->pNext){
      cout<<pNode->nData<<endl;
   }

   /*
    NODE * pNode;

    //Add items to linked list
    for (int i = 0; i < 10; i++){
        pNode = new NODE;    //allocate
	                        // memory for each node and make
                            // pointer point to the
                            //dynamically allocated memory
    	pNode->nData = i;  //put some data in the node
        AppendNode(pNode); //add node to list
    }

    // Now display each item in list
    for(pNode = pHead; pNode != NULL; pNode = pNode->pNext)
        cout<<pNode->nData<<endl;

    DeleteAllNodes();

    cout<<"Displaying afgter delete"<<endl;
    for(pNode = pHead; pNode != NULL; pNode = pNode->pNext)
        cout<<pNode->nData<<endl;
*/
    system ("pause");
    return 0;
}

//function Implementations

void AppendNode(NODE *pNode)
{
   if (pHead == NULL) {     //if list is empty
      pHead = pNode;        //make head point to pNode
      pNode->pPrev = NULL;
   }
   else {
      pTail->pNext = pNode;  //make tail point to pNode
      pNode->pPrev = pTail;
   }
   pTail = pNode;        //tail is now pNode
   pNode->pNext = NULL;  //pNode next now points to NULL
}

// Inserts a node into the list after pAfter
void InsertNode(NODE *pNode, NODE *pAfter)
{
   pNode->pNext = pAfter->pNext; //make next of new node point to "next" node
   pNode->pPrev = pAfter;               //make prev of new node point the "after" node

   if (pAfter->pNext != NULL)       // if we are NOT inserting at the end
      pAfter->pNext->pPrev = pNode;    //make prev of  "next" node point to the new node
   else
      pTail = pNode;                      //if we are inserting at the end, make new node the tail

   pAfter->pNext = pNode;   //make next of  "after" node point to new node
}

// Removes the specified node from the list
void RemoveNode(NODE *pNode)
{
   if (pNode->pPrev == NULL)  //if removing the head
       pHead = pNode->pNext;

   else
      pNode->pPrev->pNext = pNode->pNext;  //if removing a middle node

   if (pNode->pNext == NULL)  //if removing the tail
      pTail = pNode->pPrev;
       
   else
      pNode->pNext->pPrev = pNode->pPrev;

   delete pNode;  //*free the memory
}

//****** Deletes the entire list******
void DeleteAllNodes( )
{
   while (pHead != NULL)   //keep on removing until the 
                           //head points to NULL
      RemoveNode(pHead);
}

void discard_line(ifstream &in)
{
    char c;

    do
   	    in.get(c);
    while (c!='\n');
}







