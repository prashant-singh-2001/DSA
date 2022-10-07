#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int n);
void traverse();
void delNodesSmallerToLeft(struct node *n);

void main()
{
    int n;
    printf("\n\n Name : Prashant Singh \n");    
    printf("Roll Number: MCAN1CA22019\n\n");    
    printf("** Reverse a LINKED LIST **\n\n");

    //Creating A linked list :
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);
    traverse();

    //Deleting samller nodes to Left:
    delNodesSmallerToLeft(head);
    traverse();
}

//Fuction to traverse the Linked List
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

//Fuction to create the Linked List
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

//Function to delete the nodes which had greater value to their left
//I.E.: in 10,12,14,3 => 10 and 12 will be removed as 14 is bigger than them
void delNodesSmallerToLeft(struct node *n){
   struct node *curr = n;
   while(curr != NULL && curr->next != NULL){
      if(curr->data < curr->next->data){
          struct node *temp = curr->next;
          curr->data = temp->data;
          curr->next = temp->next;
          temp = NULL;
      }else{
          curr = curr->next;
      }
   }
}