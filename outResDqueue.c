#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define QSIZE 10

typedef struct
{
    int front;
    int rear;
    int item[QSIZE];
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

Queue enqueueFront(Queue q, int data)
{
    if (q.front == 0)
    {
        printf("No space to enqueue!\n");
    }
    else
    {
        q.item[--q.front] = data;
        printf("Data enqueued in front!\n");
    }
    return q;
}
Queue enqueueRear(Queue q, int data)
{
    if (!isFull(q))
    {
        q.item[++q.rear] = data;
        printf("Data enqueued in rear!\n");
    }
    else
        printf("Queue is full!\n");
    return q;
}

int dequeueFront(Queue *q)
{
    int data = -1;
    if (!isEmpty(*q))
    {
        data = q->item[q->front++];
    }
    else
        printf("Queue is empty!");
    return data;
}

// int dequeueRear(Queue *q)
// {
//     int data = -1;
//     if (!isEmpty(*q))
//     {
//         data = q->item[q->rear--];
//     }
//     else
//         printf("Queue is empty!");
//     return data;
// }

void viewQ(Queue q)
{
    if(isEmpty(q))
        printf("Queue is empty!");
    else
        while (!isEmpty(q))
        printf(" >> %d", dequeueFront(&q));
    printf("\n");
}

int main()
{
    Queue q;
    int flag = 0, i = 0, data = 0;
    printf("\nName: Prashant Singh\n");
    printf("Roll No.: MCAN1CA22019\n\n");
    printf("==>  Output Restricted Dqueue  <==\n\n");

    q = initialize(q);
    while (i<QSIZE)
    {
        q=enqueueRear(q,i);
        i++;
    }
    
    viewQ(q);

    printf("\nChoose an operation :");
    printf("\nPress 1 to Enqueue From Rear :");
    printf("\nPress 2 to Enqueue From Front :");
    printf("\nPress 3 to View Queue : ");
    printf("\nPress 4 to Dequeue From Front:");
    printf("\nPress 5 to Reset the Queue :");
    printf("\nAny other key to exit!\n");
    do
    {
        printf("\nEnter choice >> ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            q = enqueueRear(q, data);
            break;

        case 2:
            printf("Enter data : ");
            scanf("%d", &data);
            q = enqueueFront(q, data);
            break;
        case 3:
            viewQ(q);
            break;
        case 4:
            printf("%d is Dequeued from the front!\n", dequeueFront(&q));
            break;
        default:
            flag=-1;
            break;
        }
    } while (flag != -1);

    return 0;
}
