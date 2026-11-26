#include <stdio.h>

int main(void) {
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, weekday, previous_year;

    printf("Enter year (1-9999): ");
    if (scanf("%d", &year) != 1 || year < 1 || year > 9999) {
        fprintf(stderr, "Please enter a year from 1 to 9999.\n");
        return 1;
    }
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        days_in_month[1] = 29;
    }

    previous_year = year - 1;
    weekday = (previous_year * 365 + previous_year / 4 - previous_year / 100 + previous_year / 400 + 1) % 7;
    for (int month = 0; month < 12; month++) {
        printf("\n     %s %d\n", months[month], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");
        for (int i = 0; i < weekday; i++) {
            printf("    ");
        }
        for (int day = 1; day <= days_in_month[month]; day++) {
            printf("%3d", day);
            weekday = (weekday + 1) % 7;
            if (weekday == 0) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
        if (weekday != 0) {
            printf("\n");
        }
    }
    return 0;
}
