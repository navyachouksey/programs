#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int motor1, motor2;
    int *p1 = &motor1, *p2 = &motor2;

    printf("Enter speed of Motor 1 (RPM): ");
    if (scanf("%d", p1) != 1) return 1;
    printf("Enter speed of Motor 2 (RPM): ");
    if (scanf("%d", p2) != 1) return 1;

    printf("\nBefore swapping:\n");
    printf("Motor 1: %d RPM, Address: %p\n", *p1, (void *)p1);
    printf("Motor 2: %d RPM, Address: %p\n", *p2, (void *)p2);

    swap(p1, p2);

    printf("\nAfter swapping:\n");
    printf("Motor 1: %d RPM, Address: %p\n", *p1, (void *)p1);
    printf("Motor 2: %d RPM, Address: %p\n", *p2, (void *)p2);
    return 0;
}
