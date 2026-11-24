#include <stdio.h>
int main() {
    double income, tax = 0;
    printf("Enter annual taxable income ($): ");
    scanf("%lf", &income);
    if (income <= 10000) {
        tax = 0;
    }
    else if (income <= 40000) {
        tax = (income - 10000) * 0.10;
    }
    else if (income <= 80000) {
        tax = (30000 * 0.10) + (income - 40000) * 0.20;
    }
    else {
        tax = (30000 * 0.10) + (40000 * 0.20) + (income - 80000) * 0.30;
    }
    printf("Calculated annual tax liability: $%.2f\n", tax);
    return 0;
}
