#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int n);
void traverse();
void dup();

void main()
{
    int n;
    printf("\n\n Name : Prashant Singh \n");    
    printf("Roll Number: MCAN1CA22019\n\n");    
    printf("** Delete Duplicates From a LINKED LIST **\n\n");

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);
    
    printf("\n -- The original Linked List --\n");
    traverse();
    
    dup();
    
    printf("\n --- Linked List after the duplicates removed --- \n");
    traverse();
}

void dup()
{
    struct node *cur=head,*index=NULL,*temp=NULL;
    if(head==NULL)
    {
        return;
    }
    else
    {
        while (cur!=NULL)
        {
            temp=cur;
            index=temp->next;
            while(index!=NULL)
            {
                if (cur->data == index->data)
                {
                    temp->next = index->next;
                }
                else
                {
                    temp=index;
                }
                index=index->next;
            }
            cur=cur->next;
        }
        
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
    printf("Enter the data : ");
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