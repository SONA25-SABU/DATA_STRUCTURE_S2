#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book
{
    int book_id;
    char title[50];
    char author[50];
    struct book *next;
};

struct book *head;

void addBookAtBeginning();
void addBookAtEnd();
void addBookAtLocation();
void deleteBookAtBeginning();
void deleteBookAtEnd();
void deleteBookAtLocation();
void searchBook();
void displayBooks();

void main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n\n********* Library Management System *********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("1. Add a book to the beginning\n2. Add a book at last\n3. Add a book at any random location\n");
        printf("4. Delete a book from beginning\n5. Delete a book from last\n6. Delete a book from a specified location\n");
        printf("7. Search for a book\n8. Display all books\n9. Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addBookAtBeginning();
            break;
        case 2:
            addBookAtEnd();
            break;
        case 3:
            addBookAtLocation();
            break;
        case 4:
            deleteBookAtBeginning();
            break;
        case 5:
            deleteBookAtEnd();
            break;
        case 6:
            deleteBookAtLocation();
            break;
        case 7:
            searchBook();
            break;
        case 8:
            displayBooks();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Please enter a valid choice.\n");
        }
    }
}

void addBookAtBeginning()
{
    struct book *ptr;
    ptr = (struct book *)malloc(sizeof(struct book));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Book ID: ");
        scanf("%d", &(ptr->book_id));

        printf("Enter Title: ");
        scanf("%s", ptr->title);

        printf("Enter Author: ");
        scanf("%s", ptr->author);

        ptr->next = head;
        head = ptr;
        printf("\nBook inserted at the beginning");
    }
}

void addBookAtEnd()
{
    struct book *ptr, *temp;
    ptr = (struct book *)malloc(sizeof(struct book));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Book ID: ");
        scanf("%d", &(ptr->book_id));

        printf("Enter Title: ");
        scanf("%s", ptr->title);

        printf("Enter Author: ");
        scanf("%s", ptr->author);

        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("\nBook inserted at the end");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nBook inserted at the end");
        }
    }
}

void addBookAtLocation()
{
    int i, loc;
    struct book *ptr, *temp;
    ptr = (struct book *)malloc(sizeof(struct book));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Book ID: ");
        scanf("%d", &(ptr->book_id));

        printf("Enter Title: ");
        scanf("%s", ptr->title);

        printf("Enter Author: ");
        scanf("%s", ptr->author);

        printf("\nEnter the location after which you want to insert: ");
        scanf("%d", &loc);
        temp = head;
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nCan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nBook inserted at location %d", loc);
    }
}

void deleteBookAtBeginning()
{
    struct book *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nBook deleted from the beginning...\n");
    }
}

void deleteBookAtEnd()
{
    struct book *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly book of the list deleted...\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Book from the last...\n");
    }
}

void deleteBookAtLocation()
{
    struct book *ptr, *ptr1;
    int loc, i;
    printf("\nEnter the location of the book after which you want to perform deletion: ");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("\nCan't delete\n");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted book at location %d\n", loc);
}

void searchBook()
{
    struct book *ptr;
    int searchId, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter Book ID you want to search: ");
        scanf("%d", &searchId);
        while (ptr != NULL)
        {
            if (ptr->book_id == searchId)
            {
                printf("Book found at location %d\n", i + 1);
                printf("ID: %d Title: %s Author: %s", ptr->book_id, ptr->title, ptr->author);
                flag = 0;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Book not found\n");
        }
    }
}

void displayBooks()
{
    struct book *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("No books to display\n");
    }
    else
    {
        printf("\nPrinting books . . . . .\n");
        while (ptr != NULL)
        {
            printf("\nID: %d\n", ptr->book_id);
            printf("Title: %s\n", ptr->title);
            printf("Author: %s\n", ptr->author);
            ptr = ptr->next;
        }
    }
}
