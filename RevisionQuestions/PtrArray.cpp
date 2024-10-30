#include <iostream>
#define MAXI 50
#define MAXJ 75

int main() {
    int i, j;
    float *ptr;
    float values[MAXI][MAXJ];

    for (i = 0; i < MAXI; i++) {
        for (j = 0; j < MAXJ; j++) {
            values[i][j] = i + j;
        }
    }

    // Point to the last element in the array
    ptr = &values[MAXI - 1][MAXJ - 1];

    // Print the value of the last element
    std::cout << *ptr << std::endl;

    return 0;
}
