#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define QSIZE 20

typedef struct
{
    int front;
    int rear;
    int item[QSIZE];
} Queue;

int isFull(Queue q)
{
    return q.rear == QSIZE - 1;
}
int isEmpty(Queue q)
{
    return q.front > q.rear;
}

Queue initialize(Queue q)
{
    q.front = 0;
    q.rear = -1;
    return q;
}

Queue enque(Queue q, int data)
{
    if (!isFull(q))
    {
        q.item[++q.rear] = data;
        printf("Data queued!");
    }
    else
        printf("Queue is full!");
    return q;
}

int deque(Queue *q)
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

void viewQ(Queue q)
{
    while (!isEmpty(q))
        printf(" >> %d", q.item[q.front++]);
    printf("\n");
}

int main()
{
    int data, n = 0, flag = 0;
    Queue q1;
    printf("\n\n -- -- Queue Program -- -- \n\n");
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
    printf("\nAny other key to exit!\n");
    do
    {
        printf("Choose operation : ");
        scanf("%d", &n);
        printf("\n----------------------------------------\n");
        switch (n)
        {
        case 1:
            printf("Enter the data to be queued : ");
            scanf("%d", &data);
            q1 = enque(q1, data);
            break;

        case 2:
            viewQ(q1);
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
            data = deque(&q1);
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
    return 0;
}