#include <stdio.h>

#define SIZE 5

struct que {
    int jobid;
    char title[20];
};

int front = -1, rear = -1;

struct que q[SIZE];

int isFull()
{
    if (rear == SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

void Addition(struct que elem)
{
    if (isFull() == 0) {
        rear = rear + 1;
        q[rear] = elem;
        printf("Element added.\n");
    }
    else {
        printf("Queue is full.\n");
    }
}

int isEmpty()
{
    if (rear == front) {
        return 1;
    }
    else {
        return 0;
    }
}

void Deletion(struct que save)
{
    if (isEmpty() == 0) {
        front = front + 1;
        save = q[front];

        printf("Deleted element:\n");
        printf("Job ID: %d\n", save.jobid);
        printf("Title: %s\n", save.title);
    }
    else {
        printf("Queue is empty.\n");
    }
}

void Display()
{
    int i;

    if (isEmpty() == 0) {
        printf("\nQueue elements:\n");

        for (i = front + 1; i <= rear; i++) {
            printf("Job ID: %d\n", q[i].jobid);
            printf("Title: %s\n", q[i].title);
        }
    }
    else {
        printf("Queue is empty.\n");
    }
}

int main()
{
    struct que elem;
    struct que save;
    int choice;
    
        printf("\n1. Add Element\n");
        printf("2. Delete Element\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter jobid and title: ");
                scanf("%d %s", &elem.jobid, elem.title);
                Addition(elem);
                break;

            case 2:
                Deletion(save);
                break;

            case 3:
                Display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        } 

}