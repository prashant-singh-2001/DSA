#include <conio.h>
#include <stdio.h>

void insert(int *array, int *n);
void deleteA(int *array, int *n);
int search(int *array, int *n, int data);
void viewAll(int *array, int *n);
int darray(int *array, int *n);

int main()
{
    int array[50];
    int n, flag = 1;
    printf("Enter number elements to be stored in array (Less than 50!) : \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter %d value : ", i + 1);
        scanf("%d", &array[i]);
    }
    while (flag != 0)
    {
        flag = darray(array, &n);
    }
}

void insert(int *array, int *n)
{
    int index, data;
    int x;
    if (*n != 50)
    {
        *n = *n + 1;
        x = *n;

        printf("\nEnter the index of new value : ");
        scanf("%d", &index);

        printf("\nEnter the new value : ");
        scanf("%d", &data);

        while (x >= index)
        {
            array[x] = array[x - 1];
            x--;
        }

        *(array + index) = data;

        printf("Updated Array \n");
        viewAll(array, n);
    }
    else
    {
        printf("The memory of array is full!");
    }
    return;
}

void viewAll(int *array, int *n)
{
    printf("\nThe elements are :\n");
    for (int i = 0; i < *n; i++)
    {
        printf("Array[%d] : %d\n", i + 1, array[i]);
    }
    return;
}

int search(int *array, int *n, int data)
{
    for (int i = 0; i < *n; i++)
    {
        if (data == array[i])
            return i;
    }
    return -1;
}

void deleteA(int *array, int *n)
{
    int index;
    int k;
    int data;
    if (*n != 0)
    {

        viewAll(array, n);
        printf("Enter the index of data to delete : ");
        scanf("%d", &index);
        data = array[index];
        k = index;
        while (k < *n)
        {
            array[k] = array[k + 1];
            k++;
        }
        *n = *n - 1;
        printf("The deleted data is : %d", data);
        viewAll(array, n);
    }
    else
    {
        printf("The array is empty! Nothing to delete!");
        return;
    }
    return;
}

int darray(int *array, int *n)
{
    printf("Choose your Poison : \n");
    printf("Insert in the array : 1\n");
    printf("Delete from array : 2\n");
    printf("Search in the array : 3\n");
    printf("View array : 4\n");
    printf("Any other to exit!\n");
    int a = 0;
    int d = 0;
    scanf("%d", &a);
    if (a == 1)
    {
        insert(array, n);
    }
    else if (a == 2)
    {
        deleteA(array, n);
    }
    else if (a == 3)
    {
        int data;
        printf("Enter the value to search : ");
        scanf("%d", &data);
        d = search(array,n,data);
        if (d == -1)
            printf("Value is not present in array!");
        else
            printf("Value present in array at %d index!", d);
    }
    else if (a == 4)
    {
        viewAll(array,n);
    }
    else
    {
        return 0;
    }
    return 1;
}
