#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bookNode
{
    struct bookNode *prev;
    struct bookNode *next;
    char title[50]; // Assuming a maximum title length of 50 characters
    int book_id;    // Book ID
};

struct bookNode *head;

void displayLibrary();
void searchBook();
void addBook();
void deleteBook();

void main()
{
    int choice = 0;
    while (choice != 5)
    {
        printf("\n*********Library Management Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Add a book\n2. Display library\n3. Search for a book\n");
        printf("4. Delete a book\n5. Exit\n");
        printf("Enter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayLibrary();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            deleteBook();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Please enter a valid choice.\n");
        }
    }
}

void addBook()
{
    struct bookNode *ptr, *temp;
    int bookId;
    char bookTitle[50];

    ptr = (struct bookNode *)malloc(sizeof(struct bookNode));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Book ID: ");
        scanf("%d", &bookId);
        printf("Enter Book Title: ");
        scanf("%s", bookTitle);

        ptr->book_id = bookId;
        strcpy(ptr->title, bookTitle);

        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
        }
        printf("\nBook added successfully.\n");
    }
}

void deleteBook()
{
    int bookId;
    struct bookNode *ptr, *prevNode, *temp;

    if (head == NULL)
    {
        printf("\nLibrary is empty. Nothing to delete.\n");
        return;
    }

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &bookId);

    ptr = head;
    prevNode = NULL;

    while (ptr->book_id != bookId && ptr->next != head)
    {
        prevNode = ptr;
        ptr = ptr->next;
    }

    if (ptr->book_id == bookId)
    {
        // Book found, remove it from the library
        if (ptr == head && ptr->next == head)
        {
            // Only one book in the library
            free(ptr);
            head = NULL;
        }
        else if (ptr == head)
        {
            // Book to be deleted is at the beginning of the library
            prevNode = head->prev; // Update the previous node
            temp = head;           // Save the current head
            head = head->next;      // Move head to the next node
            prevNode->next = head;  // Update the previous node's next pointer
            head->prev = prevNode;  // Update the new head's prev pointer
            free(temp);             // Free the memory of the deleted book
        }
        else
        {
            // Book to be deleted is in the middle or at the end of the library
            prevNode->next = ptr->next;
            ptr->next->prev = prevNode;
            free(ptr);
        }

        printf("\nBook with ID %d deleted successfully.\n", bookId);
    }
    else
    {
        printf("\nBook with ID %d not found in the library.\n", bookId);
    }
}

void displayLibrary()
{
    struct bookNode *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nLibrary is empty.\n");
    }
    else
    {
        printf("\nBook Library:\n");
        do
        {
            printf("Book ID: %d, Title: %s\n", ptr->book_id, ptr->title);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

void searchBook()
{
    struct bookNode *ptr;
    int bookId, flag = 0;

    ptr = head;
    if (ptr == NULL)
    {
        printf("\nLibrary is empty.\n");
    }
    else
    {
        printf("\nEnter Book ID to search: ");
        scanf("%d", &bookId);

        do
        {
            if (ptr->book_id == bookId)
            {
                printf("Book found - ID: %d, Title: %s\n", ptr->book_id, ptr->title);
                flag = 1;
                break;
            }
            ptr = ptr->next;
        } while (ptr != head);

        if (flag == 0)
        {
            printf("Book not found in the library.\n");
        }
    }
}
