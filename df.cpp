#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int TOTAL_ASG = 5;
const int CAPACITY = 10;

void calculateCoursework(int assignmentMarks[][TOTAL_ASG], int mstMarks[], int coursework[], int size);
void calculateTotal(int coursework[], int finalMarks[], int totalMarks[], int size);
void printResults(string studentIds[], int coursework[], int totalMarks[], int size);
char getGrade(int totalMark);
string printLine(int length);

int main()
{
    cout << left;

    string studentIds[CAPACITY];
    int assignmentMarks[CAPACITY][TOTAL_ASG];
    int mstMarks[CAPACITY];
    int finalMarks[CAPACITY];
    int totalMarks[CAPACITY];
    int coursework[CAPACITY];
    int size = 0;

    ifstream readFile;
    readFile.open("student-grades.txt");

    if (!readFile)
    {
        cout << "File not found" << endl;
        return 1;
    }

    else
    {
        string temp;
        getline(readFile, temp);

        while (!readFile.eof())
        {
            readFile >> studentIds[size];

            for (int i = 0; i < TOTAL_ASG; i++)
            {
                // read all assignment marks
                readFile >> assignmentMarks[size][i];
            }

            // read mst and final mark
            readFile >> mstMarks[size];
            readFile >> finalMarks[size];

            size++;
        }
    }

    calculateCoursework(assignmentMarks, mstMarks, coursework, size);
    calculateTotal(coursework, finalMarks, totalMarks, size);
    printResults(studentIds, coursework, totalMarks, size);

    readFile.close();

    return 0;
}

void calculateCoursework(int assignmentMarks[][TOTAL_ASG], int mstMarks[], int coursework[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // reset student coursework
        coursework[i] = 0;

        for (int j = 0; j < TOTAL_ASG; j++)
        {
            // add all assignment marks
            coursework[i] += assignmentMarks[i][j];
        }

        // add mst mark
        coursework[i] += mstMarks[i];
    }
}

void calculateTotal(int coursework[], int finalMarks[], int totalMarks[], int size)
{
    for (int i = 0; i < size; i++)
    {
        totalMarks[i] = coursework[i] + finalMarks[i];
    }
}

void printResults(string studentIds[], int coursework[], int totalMarks[], int size)
{
    int failureCount = 0;

    cout << setw(20) << "Id" << setw(20) << "CW" << setw(20) << "Total" << setw(20) << "Grade" << endl;
    cout << printLine(70) << endl;

    for (int i = 0; i < size; i++)
    {
        char studentGrade = getGrade(totalMarks[i]);

        if (studentGrade == 'D')
        {
            failureCount++;
        }

        cout << setw(20) << studentIds[i] << setw(20) << coursework[i] << setw(20) << totalMarks[i] << setw(20) << studentGrade << endl;
        cout << printLine(70) << endl;
    }

    cout << "\nNumber of students that failed: " << failureCount << endl;
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

string printLine(int length)
{
    string line = "";

    for (int i = 0; i < length; i++)
    {
        line += "-";
    }

    return line;
}