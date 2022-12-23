#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
    int *arr;
    int n;
    printf("Total no. of values: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < (n - 1); i++)
    {
        for (int j = 0; j < (n - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\n\nSorted : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}