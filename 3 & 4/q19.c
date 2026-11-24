#include <stdio.h>
#include <stdbool.h>
#define MAX 10

static bool read_matrix(const char *name, int rows, int cols, int m[][MAX]) {
    printf("Enter elements of matrix %s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &m[i][j]) != 1) {
                return false;
            }
        }
    }
    return true;
}

static void print_matrix(int rows, int cols, int m[][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d%c", m[i][j], j < cols - 1 ? ' ' : '\n');
        }
    }
}

int main(void) {
    int rows = 0;
    int cols = 0;

    printf("Enter rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2
        || rows < 1 || rows > MAX || cols < 1 || cols > MAX) {
        fprintf(stderr, "Invalid input: rows and columns must be 1 to %d.\n", MAX);
        return 1;
    }

    int a[MAX][MAX] = {0};
    int b[MAX][MAX] = {0};

    if (!read_matrix("A", rows, cols, a) || !read_matrix("B", rows, cols, b)) {
        fprintf(stderr, "Invalid input: matrix elements must be integers.\n");
        return 1;
    }

    int difference[MAX][MAX] = {0};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            difference[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("Difference:\n");
    print_matrix(rows, cols, difference);
    return 0;
}
