#include <stdio.h>
#include <string.h>
#define MAX 20

char stack[MAX][MAX];
int top = -1;

void push(char str[]);
void pop(char str[]);
int isfull();
int isempty();
int isOperand(char ch);
void prefixToInfix(char prefix[]);

int main() {
    char prefix[20];
    printf("Enter prefix expression: ");
    scanf("%19s", prefix);
    printf("Infix expression: ");
    prefixToInfix(prefix);
    printf("\n");
    return 0;
}

void push(char str[]) {
    if (!isfull()) {
        top++;
        strcpy(stack[top], str);
    }
    else {
        printf("Stack Overflow\n");
    }
}

void pop(char str[]) {
    if (!isempty()) {
        strcpy(str, stack[top]);
        top--;
    }
    else {
        printf("Stack Underflow\n");
        str[0] = '\0';
    }
}

int isfull() {
    return top == MAX - 1;
}

int isempty() {
    return top == -1;
}

int isOperand(char ch) {
    if ((ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9')) {
        return 1;
    }

    return 0;
}

void prefixToInfix(char prefix[]) {
    char op1[MAX], op2[MAX], temp[MAX];
    int length = strlen(prefix);
    for (int i = length - 1; i >= 0; i--) {
        char ch = prefix[i];
        // operand
        if (isOperand(ch)) {
            temp[0] = ch;
            temp[1] = '\0';
            push(temp);
        }
        // If operator
        else {
            pop(op1);
            pop(op2);
            temp[0] = '\0';
            strcat(temp, "(");
            strcat(temp, op1);
            char op[2];
            op[0] = ch;
            op[1] = '\0';
            strcat(temp, op);
            strcat(temp, op2);
            strcat(temp, ")");
            push(temp);
        }
    }

    pop(temp);
    printf("%s", temp);
}

