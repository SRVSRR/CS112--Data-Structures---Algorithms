#include <iostream>
#include <stdlib.h>
using namespace std;

float do_sum(float a, float b);
float do_sum_by_ref(float a, float b, float *sum);

int main()
{
    float a;
    float b;
    float sum;

    float *ptr_sum = &sum;

    cout<<"Enter first number: ";
    cin>>a;

    cout<<"Enter second number: ";
    cin>>b;

    do_sum_by_ref(a, b, ptr_sum);

    cout<<"The sum of two numbers is: "<<sum<<endl;
    cout << "Sum address is " << ptr_sum <<endl;
    cout << "Sum ptr is " << *ptr_sum << endl;
    *ptr_sum = 10;
    cout << "Sum ptr is " << *ptr_sum << endl;
    cout << "Sum is " << sum << endl;

    if (sum > 0)
        cout<<"Sum is positive"<<endl;
    else if(sum < 0)
        cout<<"Sum is negative"<<endl;
	else
		cout<<"Sum is zero"<<endl;

    system("PAUSE");
    return 0;
}

float do_sum(float a, float b){
    return (a+b);
}

float do_sum_by_ref(float a, float b, float *sum){
    return *sum = a + b;
}
