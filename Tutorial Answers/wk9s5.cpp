#include <iostream>

using namespace std;

int factorial(int num){
    if(num == 1){
        return 1;
    }else {
        return num * factorial(num -1);
    }
}

int main(){
    int total = 0;
    total = factorial(5);
    cout << total << endl;

    return 0;
}