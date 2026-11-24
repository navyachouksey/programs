#include <stdio.h>
int main () {
    int rows = 5; // Fixed variable name to match the loop
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) { // Fixed condition to compare j with i
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
