#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

struct stack
{
    char item[100];
    int top;
};

typedef struct stack Stack;
void postFixIt(char *eq);
// Stack intialize(Stack c);
// int isFull(Stack c);
// int isEmpty(Stack c);
// Stack push(int n, Stack c);
// char pop(Stack c);
// char peep(Stack c);

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
    char i = '\0';
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

int main()
{
    char eq[20];
    int n;
    printf("Enter the equation (without space) : \n");
    scanf("%s", &eq);
    postFixIt(eq);
}

void postFixIt(char eq[])
{
    // Stack post;
    // int i = 0, j = 0;
    // post=intialize(post);
    // printf("In post");
    // while (eq[i] != '\0')
    // {
    //     printf("In while");
    //     char c = eq[i];
    //     if (c <= 'z' && c >= 'a')
    //     {
    //         printf("%c", c);
    //     }
    //     else if (c == ')')
    //     {
    //         while (peep(post) != '(')
    //         {
    //             printf("%c", pop(&post));
    //         }
    //         pop(&post);
    //     }
    //     else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(')
    //     {
    //         printf("in else");
    //         if (c == '(')
    //             post = push(c,post);
    //         else if (c == '^')
    //         {
    //             post=push(c,post);
    //         }
    //         else if ((c == '*' || c == '/') && peep(post) == '^')
    //         {
    //             printf("%c", pop(&post));
    //             post=push(c,post);
    //         }
    //         else if (c == '*' || c == '/')
    //         {
    //             post=push(c,post);
    //         }
    //         else if ((c == '+' || c == '-') && (peep(post) == '+' || peep(post) == '-'))
    //         {
    //             post=push(c,post);
    //         }
    //         else
    //         {
    //             while (peep(post) != '+' || peep(post) != '-')
    //             {
    //                 printf("%c", pop(&post));
    //             }
    //             post=push(c,post);
    //         }
    //     }

    //     i++;
    // }

    int i;
    char x, y;
    Stack s;
    s.top = -1;
    for (i = 0; eq[i] != '\0'; i++)
    {
        x = eq[i];
        if (x <= 'z' && x >= 'a')
            printf("%c", x);
        else if (x == '(')
            s = push(x, s);
        else if (x == ')')
        {
            y = pop(&s);
            while (y != '(')
            {
                printf("%c", y);
                y = pop(&s);
            }
        }
        else
        {
            if (s.top == -1 || s.item[s.top] == '(')
                s = push(x, s);
            else
            {
                y = s.item[s.top];
                if (y == '*' || y == '/')
                {
                    printf("%c", pop(&s));
                    s = push(x, s);
                }
                else if (y == '+' || y == '-')
                    if (x == '+' || x == '-')
                    {
                        printf("%c", pop(&s));
                        s = push(x, s);
                    }
                    else
                        s = push(x, s);
            }
        }
    }
    while (s.top != -1)
        printf("%c", pop(&s));
}
