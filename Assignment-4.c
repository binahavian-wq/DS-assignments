#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int regNo;
    char name[50];
    struct node *next;
};

struct node *createNode()
{
    struct node *newNode;

    newNode = malloc(sizeof(struct node));

    printf("Enter Registration Number: ");
    scanf("%d", &newNode->regNo);

    printf("Enter Name: ");
    scanf(" %s", newNode->name);

    newNode->next = NULL;

    return newNode;
}


void display(struct node *head)
{
    struct node *curr;

    if (head->next == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }

    curr = head->next;

    printf("\nStudent List:\n");

    while (curr != NULL)
    {
        printf("Registration No: %d\tName: %s\n",
               curr->regNo, curr->name);

        curr = curr->next;
    }
}


int length(struct node *head)
{
    struct node *curr;
    int i = 0;

    curr = head->next;

    while (curr != NULL)
    {
        i++;
        curr = curr->next;
    }

    return i;
}


void insertByPosition(struct node *head)
{
    struct node *curr;
    struct node *newNode;

    int pos, k, i = 1;

    k = length(head);

    printf("\nEnter position to insert: ");
    scanf("%d", &pos);

    if (pos > k + 1 || pos < 1)
    {
        printf("Data can't be inserted.\n");
        return;
    }

    newNode = createNode();

    curr = head;

    while (curr != NULL && i < pos)
    {
        i++;
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    printf("Student inserted successfully.\n");
}


void deleteByPosition(struct node *head)
{
    struct node *prev;
    struct node *curr;
    struct node *temp;

    int pos, k, ctr = 1;

    k = length(head);

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || k < pos)
    {
        printf("Data can't be deleted.\n");
        return;
    }

    prev = head;
    curr = head->next;

    while (ctr < pos && curr != NULL)
    {
        ctr++;
        prev = curr;
        curr = curr->next;
    }

    temp = curr;

    prev->next = curr->next;
    curr->next = NULL;

    free(temp);

    printf("Student deleted successfully.\n");
}


void reverse(struct node *head)
{
    struct node *prev;
    struct node *curr;
    struct node *future;

    prev = NULL;
    curr = head->next;

    while (curr != NULL)
    {
        future = curr->next;
        curr->next = prev;
        prev = curr;
        curr = future;
    }

    head->next = prev;

    printf("List reversed successfully.\n");
}


void sort(struct node *head)
{
    struct node *prev;
    struct node *curr;
    struct node *temp;

    int l, i, j;

    l = length(head);

    for (i = 1; i < l; i++)
    {
        prev = head;
        curr = head->next;

        for (j = 0; j < l - i; j++)
        {
            temp = curr->next;

            if (curr->regNo > temp->regNo)
            {
                prev->next = temp;
                curr->next = temp->next;
                temp->next = curr;

                prev = temp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    printf("List sorted successfully.\n");
}


int main()
{
    struct node *head;
    int choice;

    head = malloc(sizeof(struct node));
    head->next = NULL;

    while (1)
    {
        printf("\n===== STUDENT WORKSHOP ENROLLMENT =====\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display Students\n");
        printf("4. Count Total Participants\n");
        printf("5. Sort Students\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertByPosition(head);
                break;

            case 2:
                deleteByPosition(head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("\nTotal Participants = %d\n", length(head));
                break;

            case 5:
                sort(head);
                break;

            case 6:
                reverse(head);
                break;

            case 7:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}