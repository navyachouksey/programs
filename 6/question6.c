#include <stdio.h>

unsigned long long factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int number;

    printf("Enter a number from 0 to 20: ");
    if (scanf("%d", &number) != 1 || number < 0 || number > 20) {
        printf("Please enter a whole number from 0 to 20.\n");
        return 1;
    }

    printf("Factorial using recursion: %llu\n", factorialRecursive(number));
    printf("Factorial without recursion: %llu\n", factorialIterative(number));
    return 0;
}
