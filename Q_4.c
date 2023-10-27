// 2 D Char array
// Write a C program using functions and pointers for the following
// 1. Read and display n names
// 2. Implement bubble sort for n names
#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_NAME_LENGTH 100

// Function to read n names into an array of character strings
void readNames(char names[][MAX_NAME_LENGTH], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", names[i]);
    }
}

// Function to display n names from an array of character strings
void displayNames(char names[][MAX_NAME_LENGTH], int n) {
    printf("Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }
}

// Function to implement the bubble sort algorithm to sort names
void bubbleSort(char names[][MAX_NAME_LENGTH], int n) {
    int i, j;
    char temp[MAX_NAME_LENGTH];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the names
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    if (n > 0 && n <= MAX_NAMES) {
        char names[MAX_NAMES][MAX_NAME_LENGTH];

        readNames(names, n);
        printf("\nOriginal Names:\n");
        displayNames(names, n);

        bubbleSort(names, n);

        printf("\nSorted Names:\n");
        displayNames(names, n);
    } else {
        printf("Invalid number of names. Please enter a value between 1 and %d.\n", MAX_NAMES);
    }

    return 0;
}
