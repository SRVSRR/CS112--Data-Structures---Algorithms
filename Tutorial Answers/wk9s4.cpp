#include <iostream>

using namespace std;

int SumOf10(int num){
    if(num == -6){
        return 0;
    }
    else {
        return num + SumOf10(num - 1);
    }
}

int main(){
    int sum = 0;
    sum = SumOf10(0);
    cout << sum << endl;

    return 0;
}