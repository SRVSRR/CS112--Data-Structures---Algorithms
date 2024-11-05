#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

double VectorMedian(vector <double> &v){
    sort(v.begin(), v.end());

    int n = v.size();

    if(n == 0){
        cout << "Vector is empty" << endl;
        return 0;
    }

    if(n % 2 != 0)
    {
        return v[n/2];
    }
    else 
    {
        return (v[n/2-1] + v[n/2])/2.0;
    }
    
}

int main(){
    vector <double> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(3);

    cout << "Median is " << VectorMedian(v);

    return 0;
}