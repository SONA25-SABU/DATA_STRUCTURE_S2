#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

struct matrixStruct
{
    int book_id[ROWS][COLS];
};

struct matrixStruct library;

void insertionDisplay();
int deleteElement(int row, int col);
void displayMatrix();
int linearSearch(int bookID);
void addMatrix();
void mulMatrix();
int main()
{
    int choice, bookID, row, col;
    int continueMenu = 1; // A flag to continue the menu loop

    while (continueMenu)
    {
        printf("----------------------Library Management---------------------------\n");
        printf("Enter your Choice (1: Insert, 2: Delete, 3: Display, 4: Search, 5: Add Matrix, 6: Multiply Matrix, 0: Exit): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the book ID for the last %d books:\n", ROWS * COLS);
            insertionDisplay();
            break;
        case 2:
             printf("Enter the Row and Column of the matrix:\n");
            scanf("%d %d", &row, &col);
            deleteElement(row - 1, col - 1);
            break;
        case 3:
            displayMatrix();
            break;
        case 4:
            printf("Enter the book ID to search for: ");
            scanf("%d", &bookID);
            linearSearch(bookID);
            break;
        case 5:
            printf("----------------MATRIX ADDITION----------------------\n");
            addMatrix();
            break;
        case 6:
            printf("----------------MATRIX MULTIPLICATION----------------------\n");
            mulMatrix();
            break;
        case 0:
            continueMenu = 0; // Exit the loop
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMatrix()
{
    printf("----------------------3x3 Matrix of Books---------------------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf(" ");
        for (int j = 0; j < COLS; j++)
        {
            printf("%d     ", library.book_id[i][j]);
        }
        printf("\n");
    }
}

void insertionDisplay()
{
    // Insertion
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            scanf("%d", &library.book_id[i][j]);
        }
    }

    // Display
    printf("----------------------3x3 Matrix of Books---------------------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf(" ");
        for (int j = 0; j < COLS; j++)
        {
            printf("%d     ", library.book_id[i][j]);
        }
        printf("\n");
    }
}

int deleteElement(int row, int col)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        library.book_id[row][col] = -1; // Mark the element as deleted
        return printf("Book deleted\n");
    }
    return printf("Book not found\n");
}

int linearSearch(int bookID)
{
    printf("----------------------------Searching----------------------------------\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (library.book_id[i][j] == bookID)
            {
                return printf("Book with ID %d is found\n", bookID);
            }
        }
    }
    return printf("Book with ID %d is not found\n", bookID);
}

void addMatrix()
{
    int i, j, sum[3][3];
    for (i = 0; i < ROWS; ++i)
        for (j = 0; j < COLS; ++j)
        {
            sum[i][j] = library.book_id[i][j] + library.book_id[i][j];
        }

    for (int i = 0; i < ROWS; i++)
    {
        printf(" ");
        for (int j = 0; j < COLS; j++)
        {
            printf("%d     ", sum[i][j]);
        }
        printf("\n");
    }
}

void mulMatrix()
{
    int i, j, mul[3][3];
    for (i = 0; i < ROWS; ++i)
        for (j = 0; j < COLS; ++j)
        {
            mul[i][j] = library.book_id[i][j] * library.book_id[i][j];
        }

    for (int i = 0; i < ROWS; i++)
    {
        printf(" ");
        for (int j = 0; j < COLS; j++)
        {
            printf("%d     ", mul[i][j]);
        }
        printf("\n");
    }
}
