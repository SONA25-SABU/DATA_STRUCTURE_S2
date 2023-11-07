
// 1 D integer array
// Write a C program using functions and pointers for the following
// 1. Read and display n numbers
// 2. Read and display odd positioned elements
// 3. Display the even numbers from the set of integers
// 4. Display maximum number from the set of integers
// 5. Calculate the sum and average of n numbers

#include <stdio.h>

void readNumbers(int *arr, int n) {
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
}

void displayNumbers(int *arr, int n) {
    printf("Numbers: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void displayOddPositioned(int *arr, int n) {
    printf("Odd Positioned Elements: ");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void displayEvenNumbers(int *arr, int n) {
    printf("Even Numbers: ");
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

int findMax(int *arr, int n) {
    int max = *arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

void calculateSumAndAverage(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(arr + i);
    }
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", (float)sum / n);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    readNumbers(arr, n);
    displayNumbers(arr, n);
    displayOddPositioned(arr, n);
    displayEvenNumbers(arr, n);
    int max = findMax(arr, n);
    printf("Maximum Number: %d\n", max);
    calculateSumAndAverage(arr, n);

    return 0;
}
