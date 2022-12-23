#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define QSIZE 10
typedef struct
{
    int item[QSIZE];
    int max;
    int size;
} Queue;

Queue initialize(Queue q)
{
    q.max = 0;
    q.size = -1;
    return q;
}

int isEmpty(Queue q)
{
    if (q.size == -1)
        return 1;
    return 0;
}

int isFull(Queue q)
{
    return q.size == QSIZE - 1;
}

int setMax(Queue q)
{
    int max = -1;
    int index = -1;
    for (int i = 0; i <= q.size; i++)
    {
        if (max < q.item[i])
        {
            max = q.item[i];
            index = i;
        }
    }
    return index;
}

Queue enqueue(Queue q, int n)
{
    if (isFull(q))
        printf("Queue is Full!");
    else
    {
        q.item[++q.size] = n;
        printf("Data enqued!");
        q.max = setMax(q);
    }
    return q;
}

int dequeue(Queue *q)
{
    int data;
    if (isEmpty(*q))
        printf("Queue is Empty!");
    else
    {
        data = q->item[q->max];
        int k = q->max;
        while (k <= q->size)
        {
            q->item[k] = q->item[k + 1];
            k++;
        }
        q->size -= 1;
        q->max = setMax(*q);
    }
    return data;
}

int getMax(Queue q)
{
    return q.item[q.max];
}

void viewQue(Queue q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!");
    }
    printf("\nMax : %d\n", q.item[q.max]);
    for (int i = 0; i <= q.size; i++)
    {
        printf(" >> %d", q.item[i]);
    }
}

void main()
{
    int data, n = 0, flag = 0;
    Queue q1;
    printf("\n\n -- -- Priority Queue Program -- -- \n\n");
    printf("\n Created by Prashant Singh");
    printf("\n\n\n");

    q1 = initialize(q1);
    printf("\nChoose an operation :");
    printf("\nPress 1 to Enqueue :");
    printf("\nPress 2 to View Queue : ");
    printf("\nPress 3 to check fullness : ");
    printf("\nPress 4 to check emptiness :");
    printf("\nPress 5 to Dequeue :");
    printf("\nPress 6 to Reset the Queue :");
    printf("\nPress 6 to View Max :");
    printf("\nAny other key to exit!\n");
    do
    {
        printf("Choose operation : ");
        scanf("%d", &n);
        printf("----------------------------------------\n");
        switch (n)
        {
        case 1:
            printf("Enter the data to be queued : ");
            scanf("%d", &data);
            q1 = enqueue(q1, data);
            break;

        case 2:
            viewQue(q1);
            break;

        case 3:
            if (isFull(q1))
                printf("Queue is full!\n");
            else
                printf("Queue is not full!\n");
            break;

        case 4:
            if (isEmpty(q1))
                printf("Queue is Empty!\n");
            else
                printf("Queue is not empty!\n");
            break;

        case 5:
            data = dequeue(&q1);
            printf("Data deleted is %d", data);
            break;

        case 6:
            q1 = initialize(q1);
            break;

        default:
            flag = -1;
            break;
        }
        printf("\n----------------------------------------\n");

    } while (flag != -1);
}

// void main()
// {
//     Queue q;
//     q=initialize(q);
//     if(isEmpty(q)==1)
//         printf("Empty!"); 
// }