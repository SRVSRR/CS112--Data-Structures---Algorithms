#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    double a;
    double b;
    double sum;

    cout<<"Enter first number: ";
    cin>>a;

    cout<<"Enter second number: ";
    cin>>b;

    sum = a + b;
    double *rmt = &sum;

    cout<<"The sum of two numbers is: "<<sum<<endl;
    cout << "Address: " << rmt << endl;

    system("PAUSE");
    return 0;
}
