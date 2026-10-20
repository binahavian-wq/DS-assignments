#include <stdio.h>

#define MAX 10

char stack[MAX];
int top = -1;

void push(char ch);
char pop();
int isfull();
int isempty();
int isp(char ch);
int icp(char ch);
int isOperand(char ch);
void infixToPostfix(char infix[]);

int main() {
    char infix[20];

    printf("Enter infix expression: ");
    scanf("%19s", infix);

    printf("Postfix expression: ");
    infixToPostfix(infix);
    printf("\n");

    return 0;
}

void push(char ch) {
    if (!isfull()) {
        top++;
        stack[top] = ch;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop() {
    if (!isempty()) {
        char temp = stack[top];
        top--;
        return temp;
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

int isfull() {
    return top == MAX - 1;
}

int isempty() {
    return top == -1;
}

int isp(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '^') {
        return 3;
    }
    if (ch == '(') {
        return 0;
    }

    return -1;
}

int icp(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    if (ch == '^') {
        return 4;
    }
    if (ch == '(') {
        return 5;
    }

    return -1;
}

int isOperand(char ch) {
    if ((ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= '0' && ch <= '9')) {
        return 1;
    }

    return 0;
}

void infixToPostfix(char infix[]) {
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            printf("%c", ch);
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (!isempty() && stack[top] != '(') {
                printf("%c", pop());
            }

            if (!isempty() && stack[top] == '(') {
                pop();
            }
        }
        else {
            while (!isempty() && isp(stack[top]) >= icp(ch)) {
                printf("%c", pop());
            }

            push(ch);
        }
    }

    while (!isempty()) {
        printf("%c", pop());
    }
}

