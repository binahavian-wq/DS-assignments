#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef, exp;
    struct node *next;
} pnode;

pnode *getnode() {
    return (pnode *)malloc(sizeof(pnode));
}

void insert(pnode *head, pnode *newnode) {
    pnode *p = head->next, *prev = head;

    while (p != head && p->exp > newnode->exp) {
        prev = p;
        p = p->next;
    }

    if (p != head && p->exp == newnode->exp) {
        p->coef += newnode->coef;
        free(newnode);

        if (p->coef == 0) {
            prev->next = p->next;
            free(p);
        }
    } else {
        newnode->next = p;
        prev->next = newnode;
    }
}

pnode *create() {
    pnode *head = getnode(), *newnode;
    int i, n;

    head->exp = -1;
    head->next = head;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        newnode = getnode();

        printf("Enter coefficient: ");
        scanf("%d", &newnode->coef);

        printf("Enter exponent: ");
        scanf("%d", &newnode->exp);

        insert(head, newnode);
    }

    return head;
}

void display(pnode *head) {
    pnode *p = head->next;

    if (p == head) {
        printf("0\n");
        return;
    }

    while (p != head) {
        printf("%dx^%d", p->coef, p->exp);
        p = p->next;

        if (p != head && p->coef > 0)
            printf(" + ");
        else if (p != head)
            printf(" ");
    }

    printf("\n");
}

pnode *add_poly(pnode *p1, pnode *p2) {
    pnode *head = getnode();
    pnode *t1 = p1->next, *t2 = p2->next;
    pnode *newnode;

    head->exp = -1;
    head->next = head;

    while (t1 != p1 || t2 != p2) {
        newnode = getnode();

        if (t1 == p1) {
            newnode->coef = t2->coef;
            newnode->exp = t2->exp;
            t2 = t2->next;
        } else if (t2 == p2) {
            newnode->coef = t1->coef;
            newnode->exp = t1->exp;
            t1 = t1->next;
        } else if (t1->exp == t2->exp) {
            newnode->coef = t1->coef + t2->coef;
            newnode->exp = t1->exp;
            t1 = t1->next;
            t2 = t2->next;
        } else if (t1->exp > t2->exp) {
            newnode->coef = t1->coef;
            newnode->exp = t1->exp;
            t1 = t1->next;
        } else {
            newnode->coef = t2->coef;
            newnode->exp = t2->exp;
            t2 = t2->next;
        }

        if (newnode->coef != 0)
            insert(head, newnode);
        else
            free(newnode);
    }

    return head;
}

int main() {
    pnode *p1, *p2, *sum;

    printf("Enter first polynomial:\n");
    p1 = create();

    printf("Enter second polynomial:\n");
    p2 = create();

    printf("First polynomial: ");
    display(p1);

    printf("Second polynomial: ");
    display(p2);

    sum = add_poly(p1, p2);

    printf("Sum: ");
    display(sum);

    return 0;
}