#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define MAXSIZE 100

struct stack
{
    char item[100];
    int top;
};

typedef struct stack Stack;

Stack intialize(Stack s)
{
    s.top = -1;
    return s;
}

int isFull(Stack c)
{
    if (c.top == 99)
        return 1;
    return 0;
}

int isEmpty(Stack c)
{
    if (c.top == -1)
        return 1;
    else
        return 0;
}

Stack push(char n, Stack c)
{
    if (!isFull(c))
    {
        c.top++;
        c.item[c.top] = n;
    }
    else
        printf("Stack Full!");
    return c;
}

char pop(Stack *c)
{
    char i = -1;
    if (isEmpty(*c))
        printf("Stack empty!");
    else
    {
        i = c->item[c->top];
        c->top--;
    }
    return i;
}

char peep(Stack c)
{
    return c.item[c.top];
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
void reverse(char *exp)
{

    int size = strlen(exp);
    int j = size, i = 0;
    char temp[size];

    temp[j--] = '\0';
    while (exp[i] != '\0')
    {
        temp[j] = exp[i];
        j--;
        i++;
    }
    strcpy(exp, temp);
}
int getPostfix(char *expression)
{
    int i, j;
    Stack out;
    out = intialize(out);
    for (i = 0, j = -1; expression[i]; ++i)
    {
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z'))
            expression[++j] = expression[i];
        else if (expression[i] == ')')
            out = push(expression[i], out);
        else if (expression[i] == '(')
        {
            while (!isEmpty(out) && peep(out) != ')')
                expression[++j] = pop(&out);
            if (!isEmpty(out) && peep(out) != ')')
                return -1;
            else
                pop(&out);
        }
        else
        {
            while (!isEmpty(out) && precedence(expression[i]) <= precedence(peep(out)))
                expression[++j] = pop(&out);
            out = push(expression[i], out);
        }
    }
    while (!isEmpty(out))
        expression[++j] = pop(&out);

    expression[++j] = '\0';
}
void main()
{
    char xp[100], res[100], e, p;
    Stack operator;
    operator= intialize(operator);

    printf("\n\n Name : Abhishek Singh Tomar \n");
    printf("Roll Number: MCAN1CA22001\n\n");
    printf("** Convert Infix expression to Prefix expression **\n\n");
    
    
    printf("Enter the expression : ");
    scanf("%s", xp);
    printf("\n");
    
    reverse(xp);
    getPostfix(xp);
    reverse(xp);
    
    printf("The infix expression is : ");
    printf("%s", xp);
}