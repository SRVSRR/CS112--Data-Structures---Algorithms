#include <iostream>

using namespace std;

class DivideByZero {
    public:
        DivideByZero (int n, int d){
            num = n;
            denom = d ;
            message ="Divide by zero"; 
            }
        int getNumerator() {
            return num;
            }
        int getDenominator() {
            return denom;
            }
        string getMessage() {
            return message;
            }
    private:
        int num;
        int denom;
        string message;
};

int main()
{
    int x = 5;
    int y = 0;
    int result;
    try {
        if (y == 0) { 
            throw DivideByZero ( x, y ); 
        }
        result = x/y;
    }
    catch ( DivideByZero e ) {
        cout << e.getMessage() << endl;
        cout << "Numerator: " << e.getNumerator() << endl;
        cout << "Denominator: " << e.getDenominator() << endl; 
        }
    cout << "Goodbye" << endl;
    return 0;
}