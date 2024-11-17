#include <iostream>

using namespace std;

// Function to print numbers in descending and then ascending order
void printNum(int val) {
    if (val > 0) { // Changed to print until 0
        cout << val << endl; // Print descending value
        printNum(val - 1); // Recursive call
        cout << val << endl; // Print ascending value after recursion
    }
}

int main() {
    int val = 10;

    printNum(val); // Call the printNum function
    return 0;
}
