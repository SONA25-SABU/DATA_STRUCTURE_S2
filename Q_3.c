// 1 D Char array
// Write a C program using functions and pointers for the following
// 1. Read and display a string
// 2. Without using string builtin functions, calculate the string length
// 3. Without using string builtin functions, reverse the string
// 4. Without using string builtin functions, copy one string into other
// 5. Read a string and check whether the given character is present or not. If present, count the number of times, it is repeated

#include <stdio.h>

// Function to read and display a string
void readString(char *str) {
    printf("Enter a string: ");
    scanf("%s", str);
}

void displayString(const char *str) {
    printf("String: %s\n", str);
}

// Function to calculate the string length
int stringLength(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to reverse the string
void reverseString(char *str) {
    int length = stringLength(str);
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        // Swap characters at positions i and j
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to copy one string into another
void copyString(char *dest, const char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// Function to check if a character is present and count its occurrences
int countCharacter(const char *str, char target) {
    int count = 0;
    while (*str) {
        if (*str == target) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char inputString[100];
    char targetChar;

    readString(inputString);
    displayString(inputString);

    int length = stringLength(inputString);
    printf("String Length: %d\n", length);

    reverseString(inputString);
    printf("Reversed String: %s\n", inputString);

    char copiedString[100];
    copyString(copiedString, inputString);
    printf("Copied String: %s\n", copiedString);

    printf("Enter a character to search for: ");
    scanf(" %c", &targetChar);  // Space before %c to consume any newline character
    int charCount = countCharacter(inputString, targetChar);
    if (charCount > 0) {
        printf("Character '%c' is present %d times in the string.\n", targetChar, charCount);
    } else {
        printf("Character '%c' is not present in the string.\n", targetChar);
    }

    return 0;
}
