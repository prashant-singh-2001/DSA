#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head1 = NULL, *head2 = NULL;

void traverse(struct node *head);
struct node *create(int n, struct node *head);
struct node *combine(struct node *list1, struct node **list2);

void main()
{
    int n, m;
    struct node *headNew;
    printf("\n\n Name : Prashant Singh \n");
    printf("Roll Number: MCAN1CA22019\n\n");
    printf("** Combine two Linked List **\n\n");
    
    printf("Enter the total number of nodes of first Linked List : ");
    scanf("%d", &n);
    if (n != 0)
        head1 = create(n, head1);
    
    printf("Enter the total number of nodes of first Linked List : ");
    scanf("%d", &m);
    if (m != 0)
        head2 = create(m, head2);
    
    printf("\n -- Linked List 1 -- \n");
    traverse(head1);
    printf("\n -- Linked List 2 -- \n");
    traverse(head2);
    
    if (n < m || n == 0 || m == 0)
    {
        printf("\n\nInvalid Lists!\n");
    }
    else
    {
        printf("\n -- Combined Linked List -- \n");
        headNew = combine(head1, &head2);
        traverse(headNew);
    }
}

struct node *combine(struct node *list1, struct node **list2)
{
    struct node *nh = list1, *h1 = list1, *h2 = *list2;
    struct node *cur1, *cur2;

    while (h1 != NULL && h2 != NULL)
    {
        cur1 = h1->next;
        cur2 = h2->next;

        h2->next = cur1;
        h1->next = h2;

        h1 = cur1;
        h2 = cur2;
    }

    *list2 = h2;
    return nh;
}

void traverse(struct node *head)
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

struct node *create(int n, struct node *head)
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
    return head;
}