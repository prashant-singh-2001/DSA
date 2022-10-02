#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int n);
void insert();
void traverse();
void delete ();

int main()
{
    int n, j, flag = 0;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);
    traverse();
    while (flag == 0)
    {
        printf("\nSelect an operation :  ");
        printf("\n > Insert in the List : 1");
        printf("\n > Delete from the list: 2");
        printf("\n > Traverse the list : 3");
        printf("\nEnter your choice : ");
        scanf("%d", &j);
        
        switch (j)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            traverse();
            break;

        default:
        flag=1;
            break;
        }
    }
    return 0;
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

void traverse()
{
    struct node *temp;
    // Return if list is empty
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

void insert()
{
    struct node *np, *nr;
    int j, data, pre;
    printf("Select where to insert the node : \n");
    printf(">> Press 1 to insert at the beginning\n");
    printf(">> Press 2 to insert before specific node\n");
    printf(">> Press 3 to insert at the end\n");
    printf("Enter your choice : ");
    scanf("%d", &j);
    switch (j)
    {
    case 1:
        printf("Enter the data :");
        scanf("%d", &data);

        np = (struct node *)malloc(sizeof(struct node));
        if (np == NULL)
        {
            printf("Memory allocation error : -1. EXITING!");
        }
        else
        {
            np->data = data;
            np->next = head;
            head = np;
        }
        break;

    case 2:
        traverse();
        printf("\nEnter the data to insert before :");
        scanf("%d", &pre);
        np = (struct node *)malloc(sizeof(struct node));
        if (np == NULL)
        {
            printf("Memory allocation error : -1. EXITING!");
        }
        else
        {
            printf("Enter the data :");
            scanf("%d", &data);
            np->data = data;
            np->next = NULL;
            nr = head;
            while (data == nr->data)
            {
                nr = nr->next;
                if (nr == NULL)
                    break;
            }

            if (nr != NULL)
            {
                np->next = nr->next;
                nr->next = np;
            }
            else
            {
                printf("Entered data was not in the list!");
            }
        }
        break;

    case 3:
        np = (struct node *)malloc(sizeof(struct node));
        if (np == NULL)
        {
            printf("Memory allocation error : -1. EXITING!");
        }
        else
        {
            printf("Enter the data :");
            scanf("%d", &data);
            np->data = data;
            np->next = NULL;
            nr = head;
            while (nr->next != NULL)
                nr = nr->next;
            nr->next = np;
        }
        break;

    default:
        printf("Invalid selection!");
        break;
    }
}

void delete ()
{
    struct node *np, *nr, *xn;
    int j, data, pre;
    printf("Select where to insert the node : \n");
    printf(">> Press 1 to delete from the beginning\n");
    printf(">> Press 2 to delete specific node\n");
    printf(">> Press 3 to delete from the end\n");
    printf("Enter your choice : ");
    scanf("%d", &j);
    switch (j)
    {
    case 1:

        if (head == NULL)
        {
            printf("List is already empty.");
        }
        else
        {
            xn = head;
            head = head->next;
            printf("\nData deleted = %d\n", xn->data);
            free(xn);
        }
        break;

    case 2:
        traverse();
        printf("\nEnter the data to delete :");
        scanf("%d", &pre);
            if (head == NULL)
            {
                printf("List is already empty.");
            }
            else
            {
                xn = head;
                nr = head;
                while (nr->data != pre)
                {
                    nr = xn;
                    xn = xn->next;
                    if (xn == NULL)
                        break;
                }
                if (xn != NULL)
                {
                    if (xn == head)
                        head = head->next;
                    nr->next = xn->next;
                    xn->next = NULL;
                    free(xn);
                                }
                else
                {
                    printf("Data was not in the list!");
                }
            }
    break;

case 3:
    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        xn = head;
        nr = head;
        while (xn->next != NULL)
        {
            nr = xn;
            xn = xn->next;
        }
        if (xn == head)
        {
            data = xn->data;
            head = NULL;
        }
        else
        {
            data = xn->data;
            nr->next = NULL;
        }
        printf("\nData deleted = %d\n", data);
        free(xn);
    }
    break;

default:
    printf("Invalid selection!");
    break;
}
}