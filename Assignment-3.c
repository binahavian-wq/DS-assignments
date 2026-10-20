#include <stdio.h>
#include <string.h>

struct library
{
    int book_id;
    char book_name[50];
    int count;
};

/*Accept Function*/
void accept(struct library s[], int n)
{
    int i;
    printf("Enter number of Books: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Book ID: ");
        scanf("%d", &s[i].book_id);

        printf("Enter Book Name: ");
        scanf("%s", s[i].book_name);

        printf("Enter count of Books: ");
        scanf("%d", &s[i].count);
    }
}

/* Display Function*/
void display(struct library s[], int n)
{
    int i;
    printf("Library Books\n");
    for(i = 0; i < n; i++)
    {
        printf("Book ID: %d | Name: %s | Count: %d\n",
               s[i].book_id,
               s[i].book_name,
               s[i].count);
    }
}

/* Linear Search */
int linear_search(struct library s[], int n, int user_searchid)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(s[i].book_id == user_searchid)
        {
            return i;
        }
    }
}

/* Binary Search */
int binary_search(struct library s[], int n, int user_searchid)
{
    int l = 0;
    int h = n - 1;
    int gap;

    while(l <= h)
    {
        gap = (l + h) / 2;
        if(s[gap].book_id == user_searchid)
        {
            return gap;
        }
        else if(s[gap].book_id > user_searchid)
        {
            h = gap - 1;
        }
        else
        {
            l = gap + 1;
        }
    }
    return -1;
}

/* Insertion Sort */
void insertion_sort(struct library s[], int n)
{
    int i, j;
    struct library temp;
    for(i = 1; i < n; i++)
    {
        temp = s[i];
        j = i - 1;
        while(j >= 0 && s[j].book_id > temp.book_id)
        {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

/* Selection Sort */
void selection_sort(struct library s[], int n)
{
    int i, j, min;
    struct library temp;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(s[j].book_id < s[min].book_id)
            {
                min = j;
            }
        }
        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

int main()
{
    struct library s[10];
    int n;
    int target_id;
    int found_index;
    int choice;

    printf("Enter number of Books (maximum 10): ");
    scanf("%d", &n);

    /* Accept book details */
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter Book ID: ");
        scanf("%d", &s[i].book_id);

        printf("Enter Book Name: ");
        scanf("%s", s[i].book_name);

        printf("Enter count of Books: ");
        scanf("%d", &s[i].count);
    }

    printf("\nOriginal Library Database:");
    display(s, n);

    /* Sorting */
    printf("\n\nChoose Sorting Method:");
    printf("\n1. Insertion Sort");
    printf("\n2. Selection Sort");
    printf("\n3. Shell Sort");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            insertion_sort(s, n);
            printf("\nAfter Insertion Sort:");
            break;

        case 2:
            selection_sort(s, n);
            printf("\nAfter Selection Sort:");
            break;

        case 3:
            shell_sort(s, n);
            printf("\nAfter Shell Sort:");
            break;

        default:
            printf("\nInvalid choice!");
            return 0;
    }

    display(s, n);

    /* Searching */
    printf("\nEnter Book ID to search: ");
    scanf("%d", &target_id);

    /* Linear Search */
    found_index = linear_search(s, n, target_id);

    if(found_index != -1)
    {
        printf("\nLinear Search:");
        printf("\nBook Found at index %d", found_index);
        printf("\nBook ID: %d", s[found_index].book_id);
        printf("\nBook Name: %s", s[found_index].book_name);
        printf("\nCount: %d\n", s[found_index].count);
    }
    else
    {
        printf("\nLinear Search: Book not found.");
    }

    /* Binary Search */
    found_index = binary_search(s, n, target_id);

    if(found_index != -1)
    {
        printf("\n\nBinary Search:");
        printf("\nBook Found at index %d", found_index);
        printf("\nBook ID: %d", s[found_index].book_id);
        printf("\nBook Name: %s", s[found_index].book_name);
        printf("\nCount: %d\n", s[found_index].count);
    }
    else
    {
        printf("\nBinary Search: Book not found.\n");
    }

    return 0;
}