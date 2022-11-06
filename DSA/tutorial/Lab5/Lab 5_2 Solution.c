#include<stdio.h>

char stack[20];
int top = -1;

void push(char);
char pop();
int priority(char);



main()
{
    char exp[20];
    char x;
    int i;
    printf("Enter a valid infix expression: ");
    scanf("%s",exp);
    printf("\nThe infix expression is %s:",exp);
    printf("\nThe postfix expression is:");

    for(i=0; i < strlen(exp); i++)
    {

        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(exp[i]))
                printf("%c",pop());
            push(exp[i]);
        }

    }
    while(top != -1)
    {
        printf("%c",pop());
    }

    printf("\n");
    getch();
}


void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
