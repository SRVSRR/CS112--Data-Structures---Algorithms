#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

const int MAX_SIZE = 10;

class student {
    public: 
    string ID;
    int marks;
    char grade;

    void allocate_grade(){
     if (marks >= 80)
        grade = 'A';
     else if(marks >= 65)
        grade = 'B';
     else if(marks >= 50)
        grade = 'C';
     else
        grade = 'D';

    }
};

void discard_line(ifstream &in);
void print_students_records(student students[], int size);

int main(){
    student students[MAX_SIZE];

    int total_records;
    int choice;
    char response;
    char grade[MAX_SIZE];

    ifstream input;
    cout<<"This program determines the grades of students."<<endl;

    input.open("students.txt",ios::in);

    if(!input){
		cerr<<"File could not be opened"<<endl;
		system("PAUSE");
		exit(1);
	}
    
    discard_line(input);

    total_records = 0;

    while(input>>students[total_records].ID>>students[total_records].marks){
        students[total_records].allocate_grade();
        total_records++;
    }

    input.close();

    print_students_records (students, total_records );
    
    system("PAUSE");
    return 0;  
}

void print_students_records(student students[], int size){
    cout<<"\n\nstudents' records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<students[i].ID <<", marks: "<<students[i].marks<<", grade: " << students[i].grade<<endl;
    }
    cout<<endl;
}

void discard_line(ifstream &in)
{
    char c;

    do
   	    in.get(c);
    while (c!='\n');
}
