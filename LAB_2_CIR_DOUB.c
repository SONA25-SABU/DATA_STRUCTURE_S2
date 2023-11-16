#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bookNode
{
    char title[50];
    struct bookNode *prev;
    struct bookNode *next;
};

struct bookNode *temp, *prev, *first, *last, *newptr, *next;

int create()
{
    char ch;
    while (1)
    {
        newptr = (struct bookNode *)malloc(sizeof(struct bookNode));
        if (newptr == NULL)
        {
            printf("Memory allocation error");
            return 0;
        }
        printf("\nEnter Title of the book: ");
        scanf("%s", &newptr->title);
        newptr->next = NULL;
        newptr->prev = NULL;
        if (first == NULL)
            first = temp = last = newptr;
        else
        {
            temp->next = newptr;
            newptr->prev = temp;
            temp = temp->next;
        }

        printf("Want to add more books (Y/N): ");
        ch = getch();
        if (ch == 'n' || ch == 'N')
        {
            temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
                last = temp;
            }
            last->next = first;
            first->prev = last;
            return (0);
        }
    }
}

void display_forward()
{
    temp = first;
    if (temp == NULL)
    {
        printf("There are no books\n");
        return;
    }
    printf("Forward Display of Books: \n");
    do
    {
        printf("[%s]--->", temp->title);
        temp = temp->next;
    } while (temp != first);
    printf("(%s)\n", last->next->title);
}

void display_backward()
{
    temp = last;
    if (temp == NULL)
    {
        printf("There are no books\n");
        return;
    }
    printf("Backward Display of Books: \n");
    do
    {
        printf("[%s]--->", temp->title);
        temp = temp->prev;
    } while (temp != last);
    printf("(%s)\n", first->prev->title);
}

void search()
{
    char search_title[50];
    printf("Enter Book Title to be Searched: ");
    scanf("%s", &search_title);
    temp = first;
    int pos = 0;
    int foundFlag = 0;
    while (temp->next != NULL)
    {
        pos++;
        if (strcmpi(search_title, temp->title) == 0)
        {
            printf("Book found at position: %d\n", pos);
            foundFlag = 1;
            break;
        }
        temp = temp->next;
    }
    if (foundFlag == 0)
    {
        printf("Book is not in the list\n");
    }
}

void insert_beginning()
{
    newptr = (struct bookNode *)malloc(sizeof(struct bookNode));
    if (newptr == NULL)
    {
        printf("Memory allocation error\n");
        return;
    }
    printf("\nEnter Book Title: ");
    scanf("%s", &newptr->title);
    newptr->prev = last;
    first->prev = newptr;
    newptr->next = first;
    first = newptr;
    last->next = first;
}

void insert_end()
{
    newptr = (struct bookNode *)malloc(sizeof(struct bookNode));
    if (newptr == NULL)
    {
        printf("Memory allocation error\n");
        return;
    }
    printf("\nEnter Book Title: ");
    scanf("%s", &newptr->title);
    newptr->next = first;
    last->next = newptr;
    newptr->prev = last;
    last = newptr;
    first->prev = last;
}

void delete_beginning()
{
    temp = first;
    first = first->next;
    first->prev = last;
    temp->next = NULL;
    temp->prev = NULL;
    last->next = first;
    free(temp);
}

void delete_end()
{
    temp = last;
    last = last->prev;
    last->next = first;
    temp->prev = NULL;
    temp->next = NULL;
    first->prev = last;
    free(temp);
}

void delete_middle()
{
    if (first == NULL)
    {
        printf("\nThere are no books\n");
    }
    else
    {
        int pos, c;
        c = 0;
        printf("Enter the position of the book you want to delete: ");
        scanf("%d", &pos);

        temp = first;
        while (temp != NULL)
        {
            c++;
            if (c == pos)
            {
                prev = temp->prev;
                next = temp->next;
                prev->next = next;
                next->prev = prev;
                temp->prev = NULL;
                temp->next = NULL;
                free(temp);
                printf("\nBook at position %d deleted\n", pos);
                break;
            }
            temp = temp->next;
        }
    }
}

void main()
{
    int opt;
    opt = 0;
    first = temp = NULL;
    while (1)
    {
        printf("\n");
        printf(" +---------Book Management Menu---------+\n");
        printf(" | 1. Create Books                        |\n");
        printf(" | 2. Display Books Forward              |\n");
        printf(" | 3. Display Books Backward             |\n");
        printf(" | 4. Insert Book at the Beginning       |\n");
        printf(" | 5. Insert Book at the End             |\n");
        printf(" | 6. Delete Book at the Beginning       |\n");
        printf(" | 7. Delete Book at the End             |\n");
        printf(" | 8. Delete Book at a Specific Position |\n");
        printf(" | 9. Search for a Book                  |\n");
        printf(" | 10. Exit                              |\n");
        printf(" +---------------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            create();
            break;
        case 2:
            display_forward();
            break;
        case 3:
            display_backward();
            break;
        case 4:
            insert_beginning();
            break;
        case 5:
            insert_end();
            break;
        case 6:
            delete_beginning();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            delete_middle();
            break;
        case 9:
            search();
            break;
        case 10:
            exit(0);
        }
    }
}
