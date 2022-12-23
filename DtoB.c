#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct stack
{
    int item[MAXSIZE];
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
    if (c.top == MAXSIZE - 1)
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

Stack push(int n, Stack c)
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

int pop(Stack *c)
{
    int i = -1;
    if (isEmpty(*c))
        printf("Stack empty!");
    else
    {
        i = c->item[c->top];
        c->top--;
    }
    return i;
}

int peep(Stack c)
{
    return c.item[c.top];
}

void binary(int n)
{
    int a = n;
    Stack c;
    c = intialize(c);
    while (a != 0)
    {
        c = push(a % 2, c);
        a /= 2;
    }
    printf("Binary of %d is ", n);
    while (!isEmpty(c))
    {
        printf("%d", pop(&c));
    }
}
void main()
{
    int n;
    printf("\n\n Name : Prashant Singh \n");
    printf("Roll Number: MCAN1CA22019\n\n");
    printf("** Decimal to Binary Conversion **\n\n");

    printf("Enter number to be converted : ");
    scanf("%d", &n);
    binary(n);
    return;
}