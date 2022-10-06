#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int degree;
    int coef;
    struct node *next;
} *head1 = NULL, *head2 = NULL;

void traverse(struct node *head);
struct node *create(int n, struct node *head);
struct node *add(struct node *poly1,struct node *poly2);

void main()
{
    int n, m;
    struct node *headNew;
    printf("\n\n Name : Prashant Singh \n");
    printf("Roll Number: MCAN1CA22019\n\n");
    printf("** Polynomials Solution **\n\n");
    
    printf("Enter the highest degree in first polynomial : ");
    scanf("%d", &n);
    if (n != 0)
        head1 = create(n+1, head1);
    
    printf("Enter the highest degree in second polynomials : ");
    scanf("%d", &m);
    if (m != 0)
        head2 = create(m+1, head2);
    
    printf("\n -- Linked List 1 -- \n");
    traverse(head1);
    printf("\n -- Linked List 2 -- \n");
    traverse(head2);
    headNew=add(head1,head2);
    traverse(headNew);
}

struct node *add(struct node *poly1,struct node *poly2)
{   
    int degree=0;
    struct node *addedPoly,*nr,*np;
    addedPoly = (struct node *)malloc(sizeof(struct node));
    if (addedPoly == NULL)
    {
        printf("Memory allocation error : -1. EXITING!");
        exit(0);
    }
    addedPoly->coef = poly1->coef+poly2->coef;
    addedPoly->degree=degree;
    addedPoly->next = NULL;
    nr = addedPoly;
    poly1=poly1->next;
    poly2=poly2->next;
    while(poly1!=NULL && poly2!=NULL)
    {
     np = (struct node *)malloc(sizeof(struct node));
        if (np == NULL)
        {
            printf("Memory allocation error : -1. EXITING!");
            break;
        }
        np->coef = poly1->coef+poly2->coef;
        np->degree=++degree;
        np->next = NULL;
        nr->next = np;
        nr = nr->next;
        poly1=poly1->next;
        poly2=poly2->next;   
    }
    if(poly1==NULL && poly2!=NULL)
    {
       while(poly2!=NULL)
       {
        np = (struct node *)malloc(sizeof(struct node));
        if (np == NULL)
        {
            printf("Memory allocation error : -1. EXITING!");
            break;
        }
        np->coef = poly2->coef;
        np->degree=++degree;
        np->next = NULL;
        nr->next = np;
        nr = nr->next;
        poly2=poly2->next;
       } 
    }
    
    if(poly2==NULL && poly1!=NULL)
    {
       while(poly1!=NULL)
       {
        np = (struct node *)malloc(sizeof(struct node));
        if (np == NULL)
        {
            printf("Memory allocation error : -1. EXITING!");
            break;
        }
        np->coef = poly1->coef;
        np->degree=++degree;
        np->next = NULL;
        nr->next = np;
        nr = nr->next;
        poly1=poly1->next;
       } 
    }
    return addedPoly;
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
        printf("+ %d * X^%d ", temp->coef,temp->degree);
        temp = temp->next;
    }
    printf("\n------------------------------\n");
}

struct node *create(int n, struct node *head)
{
    struct node *np, *nr;
    int degree=0,coef, i;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Memory allocation error : -1. EXITING!");
        exit(0);
    }
    printf("Enter the coef for %d degree : ",degree);
    scanf("%d", &coef);
    head->coef = coef;
    head->degree=degree;
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
        printf("Enter the coef for %d degree: ",++degree);
        scanf("%d", &coef);
        np->coef = coef;
        np->degree=degree;
        np->next = NULL;
        nr->next = np;
        nr = nr->next;
    }
    return head;
}