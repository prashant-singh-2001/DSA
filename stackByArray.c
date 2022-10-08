#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXSIZE 100

struct stack
{
    int item[100];
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

int main()
{
    Stack c;
    printf("\n\n -- -- Stack Program -- -- \n\n");
    printf("\n Created by Prashant Singh");
    printf("\n\n\n");

    int flag = 1, counter = 0, data;
    c=intialize(c);
    while (flag == 1)
    {
        printf("\nChoose an operation :");
        printf("\nPress 1 to Push in Stack :");
        printf("\nPress 2 to Peep in Stack : ");
        printf("\nPress 3 to check fullness : ");
        printf("\nPress 4 to check emptiness :");
        printf("\nPress 5 to Pop from the stack :");
        printf("\nPress 6 to Reset the stack :");
        printf("\nAny other key to exit!\n");
        scanf("%d", &counter);
        switch (counter)
        {
        case 1:
            printf("Enter the data item : ");
            scanf("%d", &data);
            c = push(data, c);
            printf("%d successfully added to stack!");
            break;

        case 2:
            printf("%d is at the top of Stack!", peep(c));
            break;

        case 3:
            if (isFull(c))
                printf("Stack is full!");
            else
                printf("Stack is not full!");
            break;

        case 4:
            if (isEmpty(c))
                printf("Stack is Empty");
            else
                printf("Stack is not empty!");
            break;

        case 5:
            data = pop(&c);
            if (data != -1)
                printf("%d has been poped from stack", data);
            break;

        case 6:
            intialize(c);
            break;

        default:
            flag = 0;
            break;
        }
    }
    return 0;
}