#include <iostream>
#define MAXI 50
#define MAXJ 75

int main() {
    int i, j;
    float values[MAXI][MAXJ];

    for (i = 0; i < MAXI; i++) {
        for (j = 0; j < MAXJ; j++) {
            values[i][j] = i + j;
        }
    }

    std::cout << values[MAXI - 1][MAXJ - 1] << std::endl;

    return 0;
}
