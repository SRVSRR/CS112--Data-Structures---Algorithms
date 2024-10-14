#include <iostream>
#include <fstream>

using namespace std;

struct student {
    string name;
    int mark;
    char grade;
};

struct node {
    node *next;
    node *previous;
    student *studentdata;
};

char CalculateGrade(int mark){
    if(mark < 50){
        return 'F';
    }else if(mark < 65){
        return 'C';
    }else if(mark < 85){
        return 'B';
    }else {
        return 'A';
    }
}

int main(){
    node *pnode; 

    ifstream readFile;
    readFile.open("student'txt");

    string line;
    getline(readFile, line);

    while(!readFile.eof()){
        string id;
        int marks;  

        student* studentdata = new student;

        readFile >> id >> marks;
        studentdata->mark = marks;
        studentdata->name = id;
        studentdata->grade = CalculateGrade(marks);    
    }

    return 0;
}