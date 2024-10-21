#include <iostream>

using namespace std;

int main()
{
    int x = 5;
    int y = 0;
    int result;
    int exceptionCode = 25;
    try {
        if (y == 0) { throw exceptionCode; }
        result = x/y;
    }
    catch (int e) {
        if (e == 25) { 
            cout << "Divide by zero" << endl; 
            }
        else {
            cout << "Exception of unknown type" ; 
            }
    }
    cout << "Goodbye" << endl; 
    return 0; 
}