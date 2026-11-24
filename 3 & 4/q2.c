#include <stdio.h>
int main () {
    int age;
    printf("Enter applicant age: ");
    scanf("%d", &age);
    if (age >= 18) {
        printf("Eligibility Verified: Applicant is qualified for full-time processing.\n");
    }
    else {
        printf("Ineligible: Applicant must be at least 18 years old.\n");
    }
    return 0;
}
