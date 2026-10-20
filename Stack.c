#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define maxsize 50

char stack[maxsize];
int top = -1;

int IsFull(){
    if(top == maxsize - 1)
        return 1;
    else
        return 0;
}

void Push(char elem){
    if(IsFull()){
        printf("Stack is full\n");
    }
    else{
        top = top + 1;
        stack[top] = elem;
    }
}

int IsEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

char Pop(){
    if(IsEmpty()){
        printf("the stack is empty\n");
        return '\0';
    }
    else{
        top = top - 1;
        return stack[top + 1];
    }
}

char Peek(){
    if(IsEmpty())
        return '\0';
    return stack[top];
}

int precedence(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/' || ch == '%')
        return 2;
    if(ch == '^')
        return 3;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]){
    int i, j = 0;
    char ch;

    for(i = 0; infix[i] != '\0'; i++){
        ch = infix[i];

        if(ch == ' ' || ch == '\t')
            continue;

        if(isalnum(ch)){
            postfix[j] = ch;
            j++;
        }
        else if(ch == '('){
            Push(ch);
        }
        else if(ch == ')'){
            while(!IsEmpty() && Peek() != '('){
                postfix[j] = Pop();
                j++;
            }
            Pop();
        }
        else{
            while(!IsEmpty() && Peek() != '(' && precedence(Peek()) >= precedence(ch)){
                postfix[j] = Pop();
                j++;
            }
            Push(ch);
        }
    }

    while(!IsEmpty()){
        postfix[j] = Pop();
        j++;
    }

    postfix[j] = '\0';
}

void clearInputBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){
    char infix[maxsize], postfix[maxsize];
    int choice;

    do{
        printf("\n=== Expression Conversion using Stack ===\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Exit\n");
        printf("Enter choice: ");

        if(scanf("%d", &choice) != 1){
            printf("Invalid input, please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch(choice){
            case 1:
                top = -1;
                printf("Enter infix expression: ");
                fgets(infix, maxsize, stdin);
                infix[strcspn(infix, "\n")] = '\0';

                infixToPostfix(infix, postfix);
                printf("Postfix expression: %s\n", postfix);
                break;
            case 2:
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 2);

    return 0;
}