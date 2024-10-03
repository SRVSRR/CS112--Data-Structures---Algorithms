#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

// Student struct
struct Student {
    string id;
    int marks;
    char grade;
};

// NODE pointing to student struct
struct NODE {
    NODE *pNext;
    NODE *pPrev;
    Student *studentData; // Pointer to Student object
};

NODE *pHead = NULL, *pTail = NULL;

// Prototypes
void AppendNode(NODE *pNode);
void InsertNode(NODE *pNode, NODE *pAfter);
void RemoveNode(NODE *pNode);
void DeleteAllNodes();
void discard_line(ifstream &in);

// Determine Grade
char calculateGrade(int marks) {
    if (marks >= 85) return 'A';
    if (marks >= 70) return 'B';
    if (marks >= 50) return 'C';
    if (marks >= 30) return 'D';
    return 'F';
}

int main() {
    NODE *pNode;
    
    // Read file
    ifstream readFile("wk10_students.txt"); 

    string discardLine;
    getline(readFile, discardLine); // discard first line
    
    while (!readFile.eof()) {
        string id;
        int marks;
        
        readFile >> id >> marks;

        // Create a new student object
        Student* newStudent = new Student;
        newStudent->id = id;
        newStudent->marks = marks;
        newStudent->grade = calculateGrade(marks);

        // Create a new node to store this student
        pNode = new NODE;
        pNode->studentData = newStudent;
        
        // Append node to the linked list
        AppendNode(pNode);
    }

    readFile.close();

    // Print student data (ID and marks)
    for (pNode = pHead; pNode != NULL; pNode = pNode->pNext) {
        cout << "Student ID: " << pNode->studentData->id
             << ", Marks: " << pNode->studentData->marks
             << ", Grade: " << pNode->studentData->grade << endl;
    }

    DeleteAllNodes();
}

// Appends a node at the end of the list
void AppendNode(NODE *pNode) {
    if (pHead == NULL) {
        // List is empty
        pHead = pTail = pNode;
        pNode->pNext = pNode->pPrev = NULL;
    } else {
        // Append at the end
        pTail->pNext = pNode;
        pNode->pPrev = pTail;
        pNode->pNext = NULL;
        pTail = pNode;
    }
}

// Deletes all nodes in the list
void DeleteAllNodes() {
    NODE *pTemp = pHead;
    while (pTemp != NULL) {
        NODE *pDel = pTemp;
        pTemp = pTemp->pNext;
        delete pDel->studentData; // Free memory for the student object
        delete pDel;              // Free memory for the node
    }
    pHead = pTail = NULL;
}
