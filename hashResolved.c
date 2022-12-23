#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int hashKey(int num, int size)
{
    return (num % size);
}

int isPrime(int size)
{
    if (size == 0 || size == 1)
    {
        return 0;
    }
    for (int i = 2; i < size / 2; i++)
    {
        if (size % i == 0)
            return 0;
    }
    return 1;
}

// int resolver(int *arr, int num, int size)
// {
//     for (int i = num; i < size; i++)
//     {
//         if (arr[i] == 0)
//             return i;
//     }
//     return -1;
// }

int resolverQ(int *arr, int num, int size)
{
    int j = 0;
    for (int i = num; i < size; i = num + pow(j, 2))
    {
        if (arr[i] == 0)
            return i;
        j++;
    }
    return -1;
}

int deleteResolverQ(int *arr, int num, int size, int data)
{
    int j = 0;
    for (int i = num; i < size; i = num + pow(j, 2))
    {
        if (arr[i] == data)
            return i;
        j++;
    }
    return -1;
}

void diss(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            printf("%d \n", arr[i]);
        }
    }
}

void main()
{
    int n, *arr;
    int data, c = 1;
    int choice = 0;
    int index, m = 0;
    
    printf("\n\nName : Prashant Singh \n");
    printf("Roll Number : MCAN1CA22019\n\n");
    printf("** Hashtable With Quadratic Probing **\n\n");

    printf("Enter the number of values : ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }
    for (int i = n; i >= 0; i--)
    {
        if (isPrime(i))
        {
            m = i;
            break;
        }
    }
    if (m != 0)
    {

        while (c == 1)
        {
            printf("Select any one :\n");
            printf("1: Insert | 2: Delete | 3: Show Table | 0: Exit\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the data: ");

                scanf("%d", &data);

                index = hashKey(data, m);
                index = resolverQ(arr, index, n);
                if (index != -1)
                {
                    arr[index] = data;
                }
                else
                    printf("No space in HashTable!\n");
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                index = deleteResolverQ(arr, hashKey(data, m), n, data);
                if (index != -1)
                {
                    printf("%d is deleted fom Table!\n", arr[index]);
                    arr[index] = 0;
                }
                else
                    printf("Data was not in the table!\n");
                break;

            case 3:
                diss(arr, n);
                break;

            case 0:
                c = 9;
                break;
            
            default:
                printf("Invalid Input!\n");
                break;
            }
        }
    }
    else
        printf("No need of hash Table");
}