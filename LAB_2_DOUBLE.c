#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    int book_id;
    char title[50];
    char author[50];
};

struct node {
    struct node *prev;
    struct node *next;
    struct book data;
};

struct node *head;

void addBook();
void deleteBook();
void displayBooks();
void searchBook();

void main() {
    int choice = 0;
    while (choice != 5) {
        printf("\n********* Library Management System *********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1. Add a book to the library\n2. Delete a book\n3. Display all books \n4. Search for a book\n5. Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice) {
            case 1:
                addBook(); // Add a book to the library
                break;
            case 2:
                deleteBook(); // Delete a book
                break;
            case 3:
                displayBooks(); // Display all books
                break;
            case 4:
                searchBook(); // Search for a book
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice..\n");
        }
    }
}

void addBook() {
    struct node *ptr, *temp;
    int id;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter book ID: ");
        scanf("%d", &id);
        printf("Enter book title: ");
        scanf("%s", ptr->data.title);
        printf("Enter book author: ");
        scanf("%s", ptr->data.author);
        ptr->data.book_id = id;
        if (head == NULL) {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
        printf("\nBook added to the library\n");
    }
}

void deleteBook() {
    struct node *ptr, *temp;
    int id;
    printf("\nEnter the book ID to delete: ");
    scanf("%d", &id);
    ptr = head;

    while (ptr != NULL) {
        if (ptr->data.book_id == id) {
            if (ptr->prev == NULL) {
                head = ptr->next;
                head->prev = NULL;
                free(ptr);
            } else {
                temp = ptr->prev;
                temp->next = ptr->next;
                if (ptr->next != NULL) {
                    ptr->next->prev = temp;
                }
                free(ptr);
            }
            printf("\nBook with ID %d deleted\n", id);
            return;
        }
        ptr = ptr->next;
    }

    printf("\nBook with ID %d not found\n", id);
}

void displayBooks() {
    struct node *ptr;
    printf("\nPrinting books in the library...\n");
    ptr = head;

    while (ptr != NULL) {
        printf("ID: %d, Title: %s, Author: %s\n", ptr->data.book_id, ptr->data.title, ptr->data.author);
        ptr = ptr->next;
    }
}

void searchBook() {
    struct node *ptr;
    int id;
    printf("\nEnter the book ID to search: ");
    scanf("%d", &id);
    ptr = head;

    while (ptr != NULL) {
        if (ptr->data.book_id == id) {
            printf("\nBook found - ID: %d, Title: %s, Author: %s\n", ptr->data.book_id, ptr->data.title, ptr->data.author);
            return;
        }
        ptr = ptr->next;
    }

    printf("\nBook with ID %d not found\n", id);
}
