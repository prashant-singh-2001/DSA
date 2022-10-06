#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int n);
void reverse(int n);
void traverse();
//void reverse1();

void main()
{
    int n;
    printf("\n\n Name : Prashant Singh \n");    
    printf("Roll Number: MCAN1CA22019\n\n");    
    printf("** Reverse a LINKED LIST **\n\n");

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);
    traverse();
    
    reverse(n);
    traverse();
}

void reverse(int n)
{
    int rev[n];
    int j = 0;
    struct node *nr, *np, *temp = head;
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }
    while (temp != NULL)
    {
        rev[j] = temp->data;
        temp = temp->next;
        j++;
    }
    head->data = rev[n - 1];
    head->next = NULL;
    nr = head;
    for (int i = n - 2; i >= 0; i--)
    {
        np = (struct node *)malloc(sizeof(struct node));
        if (np == NULL)
        {
            printf("Memory allocation error : -1. EXITING!");
            break;
        }
        np->data = rev[i];
        np->next = NULL;
        nr->next = np;
        nr = nr->next;
    }
}


void traverse()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }
    temp = head;
    printf("\n------------------------------\n");
    while (temp != NULL)
    {
        printf(">> %d ", temp->data);
        temp = temp->next;
    }
    printf("\n------------------------------\n");
}

void create(int n)
{
    struct node *np, *nr;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Memory allocation error : -1. EXITING!");
        exit(0);
    }
    printf("Enter the data: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    nr = head;
    for (i = 1; i < n; i++)
    {
        np = (struct node *)malloc(sizeof(struct node));
        if (np == NULL)
        {
            printf("Memory allocation error : -1. EXITING!");
            break;
        }
        printf("Enter the data : ");
        scanf("%d", &data);
        np->data = data;
        np->next = NULL;
        nr->next = np;
        nr = nr->next;
    }
}


// void reverse1()
// {
//     struct node *nr=NULL, *np=NULL, *temp = head;
//     if (head == NULL)
//     {
//         printf("List is empty.");
//         return;
//     }
//     while(temp!=NULL)
//     {
//         np=temp->next;
//         temp->next=nr;
//         nr=temp;
//         temp=np;
//     }    
//     head=nr;
// }