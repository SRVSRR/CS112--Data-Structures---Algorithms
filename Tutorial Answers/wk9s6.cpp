#include <iostream>

using namespace  std;

int powerfunction(int num, int exponent){
    if(exponent == 0){
        return 1;
    }else {
        return num * powerfunction(num, exponent - 1);
    }
}

int main(){
    int base;
    int exponent;
    cout  << "Enter base:" << endl;
    cin >> base;

    cout << "Enter exponent:" << endl;
    cin >> exponent;

    int answer = powerfunction(base, exponent);

    cout << answer << endl;


    return 0;
}