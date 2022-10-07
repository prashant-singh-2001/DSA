#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int n);
void reverse();
void traverse();
void deleteIfLess(struct node *hRef);
void delNodes(struct node *n);

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

    // reverse();
    // deleteIfLess(head);
    // reverse();

    delNodes(head);
    traverse();
}

void deleteIfLess(struct node* hRef)
{
    struct node* current = hRef;
  
    struct node* maxnode = hRef;
    struct node* temp;
  
    while (current != NULL && current->next != NULL) {
        if (current->next->data < maxnode->data) {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
  
        else {
            current = current->next;
            maxnode = current;
        }
    }

}

void reverse()
{
    struct node *nr=NULL, *np=NULL, *temp = head;
    if (head == NULL)
    {
        printf("List is empty.");
        return;
    }
    while(temp!=NULL)
    {
        np=temp->next;
        temp->next=nr;
        nr=temp;
        temp=np;
    }    
    head=nr;
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

void delNodes(struct node *n){
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