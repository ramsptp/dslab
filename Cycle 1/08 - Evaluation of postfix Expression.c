#include <stdio.h>
#include <ctype.h>

int stack[20];  
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int operation(int a, int b, char current_character)
{
    switch (current_character)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;  
    }
}

void main()
{
    char exp[20];
    int num, a, b;
    printf("Enter the expression: ");
    scanf("%s", exp);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isalnum(exp[i]))
        {
            num = exp[i] - '0';  //same as exp[i] - 48
            push(num);
        }
        else
        {
            b = pop();  
            a = pop();  
            push(operation(a, b, exp[i]));
        }
    }
    printf("The result of %s is %d\n", exp, pop());
}
