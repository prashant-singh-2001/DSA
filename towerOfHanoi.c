#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAXSIZE 100

struct stack
{
    char item[100];
    char top;
};

typedef struct stack Stack;
void Hanoi(int , Stack*, Stack*, Stack*);
void viewAll(Stack);
Stack intial, final, Helping;

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
    return c.top == -1;
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

void Hanoi(int n, Stack *intial, Stack *Helping, Stack *final)
{
    char c;
    if (n > 0)
    {

        Hanoi(n - 1, intial, final, Helping);
        c = pop(intial);
        *final = push(c, *final);
        Hanoi(n - 1, Helping, intial, final);
    }
}
void viewAll(Stack c)
{
    if (isEmpty(c))
        printf("Stack is empty.\n");
    else
    {
        while (!(isEmpty(c)))
        {
            printf("%c\n", pop(&c));
        }
    }
}
void process(int n, char from_tower, char to_tower, char help_tower)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from tower %c to tower %c", from_tower, to_tower);
        return;
    }
    process(n-1, from_tower, help_tower, to_tower);
    printf("\n Move disk %d from tower %c to tower %c", n, from_tower, to_tower);
    process(n-1, help_tower, to_tower, from_tower);
}
void main()
{
    int n, i = 0;
    char c;
    
    intial = intialize(intial);
    final = intialize(final);
    Helping = intialize(Helping);
    
    printf("\n\n Name : Prashant Singh \n");    
    printf("Roll Number: MCAN1CA22019\n\n");    
    printf("** Tower of Hanoi **\n\n");

    printf("Enter the size of tower: ");
    scanf("%d", &n);
    
    c = (char)(n + 64);
    for (int i = 0; i < n; i++)
    {
        intial = push(c, intial);
        c--;
    }

    printf("\nThe A (intial) tower is : \n");
    viewAll(intial);
    printf("\nThe B (final) tower is : \n");
    viewAll(final);
    printf("\nThe C (helping) tower is : \n");
    viewAll(Helping);
    
    printf("\n-------- Process -----------\n");
    Hanoi(n,&intial,&Helping,&final);
    process(n,'A', 'B', 'C');
    printf("\n---------------------------\n");
    
    printf("\nThe A (intial) tower is : \n");
    viewAll(intial);
    printf("\nThe B (final) tower is : \n");
    viewAll(final);
    printf("\nThe C (helping) tower is : \n");
    viewAll(Helping);
    return ;
}