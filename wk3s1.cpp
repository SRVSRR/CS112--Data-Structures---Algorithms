#include <iostream>
#include <fstream>

using namespace std;

const int TOTAL_ASSIGNS = 5;

void determine_students_coursework(int assignment[][TOTAL_ASSIGNS], int mst[], int coursework[], int size){
    for(int k = 0; k < size; k++){
        coursework[k] = 0;
            for(int i = 0; i < TOTAL_ASSIGNS; i++){
            coursework[k] = coursework[k] + assignment[k][i];
        }
        coursework[k] = coursework[k] + mst[k];
    }
}

void print_students_coursework(string id[], int coursework[], int size){
    for(int i = 0; i < size; i++){
        if(coursework[i] < 49){

        }
    }
}

char getGrade(int totalMark)
{
    if (totalMark < 50)
    {
        return 'D';
    }
    else if (totalMark < 65)
    {
        return 'C';
    }
    else if (totalMark < 80)
    {
        return 'B';
    }
    else
    {
        return 'A';
    }
}

int main(){
    ifstream input;
    input.open("students2.txt");

    if (!input) {
        cerr << "Unable to open file students2.txt";
        exit(1);   // call system to stop
    }

    string line;
    getline(input, line);

    const int CAPACITY = 7;
    int mst[CAPACITY], final_exam[CAPACITY], assignment_totals[CAPACITY][TOTAL_ASSIGNS],coursework[TOTAL_ASSIGNS];
    string student_ID[CAPACITY];

    int index = 0;
    while(input){
        input >> student_ID[index];

        for (int i = 0; i < TOTAL_ASSIGNS; i++)
        {
            input >> assignment_totals[index][i];
        }

        input >> mst[index];
        input >> final_exam[index];
        index++;
    }

    determine_students_coursework(assignment_totals, mst, coursework, TOTAL_ASSIGNS);
    cout << right << "Student ID" << setw(12) << "Coursework" << setw(8) << "Finals" << endl;; 

    for(int i = 0; i < CAPACITY; i++){
        cout << right << student_ID[i] << setw(12) << coursework[i] << setw(8) << final_exam[i] << endl;
    }

    int overall[CAPACITY];
    for(int i = 0; i < CAPACITY; i++){
        overall[i] = coursework[i] + final_exam[i];
    }

    cout << endl;

     for(int i = 0; i < CAPACITY; i++){
        cout << right << student_ID[i] << setw(12) << overall[i] << endl;
    }

    input.close();
    return 0;
}
