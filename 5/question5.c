#include <stdio.h>
#include <string.h>

#define SIZE 200

void readString(char str[], int size) {
    if (fgets(str, size, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}

int main(void) {
    char first[SIZE], second[SIZE], result[SIZE * 2];
    char input[20];
    int choice;

    do {
        printf("\n--- String Operations ---\n");
        printf("1. Find length\n2. Copy a string\n3. Concatenate strings\n");
        printf("4. Compare strings\n5. Find a substring\n6. Exit\n");
        printf("Enter your choice: ");
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }
        if (choice == 6) {
            printf("Goodbye!\n");
            break;
        }
        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter a string: ");
        readString(first, SIZE);
        if (choice >= 3) {
            printf("Enter another string: ");
            readString(second, SIZE);
        }

        switch (choice) {
            case 1:
                printf("Length: %zu\n", strlen(first));
                break;
            case 2:
                strcpy(result, first);
                printf("Copied string: %s\n", result);
                break;
            case 3:
                strcpy(result, first);
                strcat(result, second);
                printf("Concatenated string: %s\n", result);
                break;
            case 4: {
                int comparison = strcmp(first, second);
                if (comparison == 0) printf("The strings are equal.\n");
                else if (comparison < 0) printf("The first string comes before the second.\n");
                else printf("The first string comes after the second.\n");
                break;
            }
            case 5: {
                char *found = strstr(first, second);
                if (found != NULL)
                    printf("Substring found at position %ld.\n", (long)(found - first + 1));
                else
                    printf("Substring not found.\n");
                break;
            }
        }
    } while (1);

    return 0;
}
