#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define QSIZE 5

typedef struct
{
    int front;
    int rear;
    int item[QSIZE];
} Queue;
Queue initalize(Queue);
int isFull(Queue);
int isEmpty(Queue);
int dequeue(Queue *);
Queue enqueue(Queue, int);
void viewQ(Queue);

Queue initalize(Queue q)
{
    q.front = 0;
    q.rear = -1;
    return q;
}

int isEmpty(Queue q)
{
    if (q.rear ==-1 && q.front==0)
        return 1;    
    return 0;
}

int isFull(Queue q)
{
    if ((q.front == 0 && q.rear == QSIZE - 1))
        return 1;
    else if ((q.front!=0 && q.front == q.rear + 1))
    {
        return 1;
    }
    
    return 0;
}

Queue enqueue(Queue q, int n)
{
    if ((isFull(q)))
    {
        printf("Queue is Full!");
    }
    else
    {
        if (q.rear == QSIZE - 1 && q.front != 0)
        {
            q.rear = 0;
            q.item[q.rear] = n;
        }
        else if (q.front > 0 && q.rear != q.front - 1)
            q.item[++q.rear] = n;
        else
            q.item[++q.rear] = n;
    }
    return q;
}

int dequeue(Queue *q)
{
    int data = -1;
    if (!(isEmpty(*q)))
    {
        if (q->front == q->rear)
        {
            data = q->item[q->rear];
            *q = initalize(*q);
        }
        else if (q->front == QSIZE - 1 && q->rear >= 0)
        {
            data = q->item[q->front];
            q->front = 0;
        }
        else
        {
            data = q->item[q->front];
            q->front++;
        }
    }
    else
        printf("Queue is empty!");
    return data;
}

void viewQ(Queue q)
{
    if(isEmpty(q))
        printf("Queue is empty!");
    else
        while (!isEmpty(q))
        printf(" >> %d", dequeue(&q));
    printf("\n");
}

int main()
{
    int data, n = 0, flag = 0;
    Queue q1;
    printf("\n Name: Prashant Singh\n");
    printf("Roll No.: MCAN1CA22019\n");
    printf("\n\n -- --> Circular Queue Program <-- -- \n\n");
    

    q1=initalize(q1);
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
            q1 = enqueue(q1, data);
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
            data = dequeue(&q1);
            printf("Data deleted is %d", data);
            break;

        case 6:
            q1 = initalize(q1);
            printf("Queue reseted succesfully!");
            break;

        default:
            flag = -1;
            break;
        }
        printf("\n----------------------------------------\n");

    } while (flag != -1);
    return 0;
}