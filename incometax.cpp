#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

double determine_tax(int sincome, int sage);
void discard_line(ifstream &in);
void print_students_records(string *sid, int *smarks, int *sincome,int *sage, int size);

int main()
{
    string *id;
    int *income;
    int *age;
    int *tax;
    int total_records;
    int choice;
    char response;

    ifstream input;

    cout<<"This program determines the tax of customers."<<endl;

    input.open("info.txt",ios::in);

    if(!input){
		cerr<<"File could not be opened"<<endl;
		system("pause");
        return 0;
	}

    int NumCustomers;
    string ignore;
    input >> ignore >> NumCustomers;
    
    cout << "The number  is " << NumCustomers << endl;

    //ignore a line from the current position of the ifstream cursor
    discard_line(input);
    discard_line(input);
    discard_line(input);

    id = new string[NumCustomers];
    income = new int[NumCustomers];
    age = new int[NumCustomers];
    tax = new int[NumCustomers];

    total_records = 0;

    while(input>>ws && !input.eof()){
        input>>id[total_records];
        input>>income[total_records];
        input>>age[total_records];
        total_records++;
    }

    for (int i = 0; i < total_records; i++){
        tax[i] = determine_tax(income[i], age[i]);
    }

    input.close();

    print_students_records (id, income, age, tax, total_records );

    delete []id;
    delete []income;
    delete []age;
    delete []tax;

    system("PAUSE");
    return 0;
}

void print_students_records(string *sid, int *sincome, int *sage, int *stax ,int size){
    cout<<"\n\nCustomer records"<<endl<<endl;
    for (int i = 0; i < size; i++){
        cout<<"id: "<<sid[i]<<", income: "<<sincome[i]<<", age: "<<sage[i]<<", tax: "<<stax[i]<<endl;
    }
    cout<<endl;
}

double determine_tax(int sincome, int sage){
     double stax;
     if(sage > 30){
        if (sincome > 30000)
            stax = sincome * .18;
        else {
            stax = sincome * .15;
        }
     }
     else {
        if(sincome > 30000)
            stax = sincome * .18;
        else
            stax = sincome * 0.12;
     }
     return stax;
}

void discard_line(ifstream &in)
{
    char c;

    do
   	    in.get(c);
    while (c!='\n');
}
