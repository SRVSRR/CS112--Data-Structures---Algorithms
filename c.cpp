#include <iostream> 
using namespace std;

int main() {
    double num1, num2; 
    char oper;  // Renamed from 'operator' to 'oper'

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): "; 
    cin >> oper;
    cout << "Enter second number: ";
    cin >> num2;

    switch (oper)  // Updated the variable name here
    {
        case '+': 
            cout << "Result: " << num1 + num2 << endl;
            break; 
        case '-': 
            cout << "Result: " << num1 - num2 << endl;
            break; 
        case '*': 
            cout << "Result: " << num1 * num2 << endl; 
            break; 
        case '/':
            if(num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero!" << endl; 
            }
            break;
        default: 
            cout << "Invalid operator" << endl; 
            break;
    }
    return 0; 
}
