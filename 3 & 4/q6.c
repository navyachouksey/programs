#include <stdio.h>
int main () {
    int row = 4; int cols = 6;
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= cols; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
