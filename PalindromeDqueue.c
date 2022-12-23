#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define QSIZE 10

typedef struct
{
    int front;
    int rear;
    char item[QSIZE];
} Queue;

Queue initialize(Queue q)
{
    q.front = 0;
    q.rear = -1;
    return q;
}

int isEmpty(Queue q)
{
    return q.front > q.rear;
}

int isFull(Queue q)
{
    return q.rear == QSIZE - 1;
}


Queue enqueueFront(Queue q, char data)
{
    if (q.front == 0)
    {
        printf("No space to enqueue!");
    }
    else
    {
        q.item[--q.front] = data;
        printf("\nData enqueued!");
    }
    return q;
}
Queue enqueueRear(Queue q, char data)
{
    if (!isFull(q))
    {
        q.item[++q.rear] = data;
    }
    else
        printf("Queue is full!");
    return q;
}

char dequeueFront(Queue *q)
{
    char data = -1;
    if (!isEmpty(*q))
    {
        data = q->item[q->front++];
    }
    else
        printf("Queue is empty!");
    return data;
}

char dequeueRear(Queue *q)
{
    char data = -1;
    if (!isEmpty(*q))
    {
        data = q->item[q->rear--];
    }
    else
        printf("Queue is empty!");
    return data;
}

int main()
{
    Queue q;
    char str[10];
    int flag = 0, i = 0;
    printf("\nName: Prashant Singh\n");
    printf("Roll No.: MCAN1CA22019\n\n");
    printf("==>  Palindrome Checker With Dqueue  <==\n\n");

    q = initialize(q);
    printf("Enter the string : ");
    scanf("%s", str);
    while (str[i] != '\0')
    {
        q = enqueueRear(q, str[i]);
        i = i + 1;
    }
    while (q.rear != q.front && !(isEmpty(q)))
    {
        char f = dequeueFront(&q);
        char r = dequeueRear(&q);
        if (f != r)
        {
            printf("%c != %c\n", f, r);
            flag = 1;
            break;
        }
        printf("%c == %c\n", f, r);
    }
    if (flag == 0)
    {
        if (!isEmpty(q))
            printf("Middle Character : %c\n", dequeueFront(&q));
        printf("The given string is : Palindrome!");
    }
    else
    {
        printf("The given string is : Not Plaindrome!");
    }

    return 0;
}
