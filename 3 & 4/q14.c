#include <stdio.h>
int main() {
    float marks;
    printf("Enter student percentage: ");
    scanf("%f", &marks);
    if (marks >= 90) {
        printf("Grade: A(Outstanding Performance)\n");
    }
    else if (marks >= 80) {
        printf("Grade: B(Great)\n");
    }
    else if (marks >= 70) {
        printf("Grade: C(Good)\n");
    }
    else if (marks >= 60) {
        printf("Grade: D(Satisfactory)\n");
    }
    else {
        printf("Grade: F(Fail- better luck next time)\n");
    }
    return 0;
}
