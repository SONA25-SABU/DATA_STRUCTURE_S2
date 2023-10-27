// 2 D integer array
// Write a C program using functions and pointers for the following
// 1. Read and display n*n matrix
// 2. Calculate the row total of a given matrix
// 3. Check whether the given matrix is identity matrix or not

#include <stdio.h>

void readMatrix(int *matrix, int n) {
    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", matrix + i * n + j);
        }
    }
}

void displayMatrix(int *matrix, int n) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(matrix + i * n + j));
        }
        printf("\n");
    }
}

int calculateRowTotal(int *matrix, int n, int row) {
    int total = 0;
    for (int j = 0; j < n; j++) {
        total += *(matrix + row * n + j);
    }
    return total;
}

int isIdentityMatrix(int *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (*(matrix + i * n + j) != 1) {
                    return 0; // Not an identity matrix
                }
            } else {
                if (*(matrix + i * n + j) != 0) {
                    return 0; // Not an identity matrix
                }
            }
        }
    }
    return 1; // It is an identity matrix
}

int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    readMatrix(&matrix[0][0], n);
    displayMatrix(&matrix[0][0], n);

    int row;
    printf("Enter the row for which you want to calculate the total: ");
    scanf("%d", &row);
    if (row >= 0 && row < n) {
        int total = calculateRowTotal(&matrix[0][0], n, row);
        printf("Total for row %d: %d\n", row, total);
    } else {
        printf("Invalid row number.\n");
    }

    if (isIdentityMatrix(&matrix[0][0], n)) {
        printf("The matrix is an identity matrix.\n");
    } else {
        printf("The matrix is not an identity matrix.\n");
    }

    return 0;
}
