#include <stdio.h>
#include <conio.h>
void selection(int *, int);

void main()
{
    int arr[] = {6, 9, 11, 2, 6, 43, 89, 10, 87, 43, 32};
    int n = 11;
    for (int i = 0; i < n; i++)
    {
        printf("> %d\t", arr[i]);
    }
    printf("\n");
    selection(arr, n);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("> %d\t", arr[i]);
    // }
    // printf("\n");
}
void selection(int *arr, int n)
{
    int i, j, k, min;
    for (j = 0; j < n - 1; j++)
    {
        min = arr[j];
        k = j;
        for (i = j + 1; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                k = i;
            }
        }
        arr[k] = arr[j];
        arr[j] = min;
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("> %d\t", arr[i]);
    }
    printf("\n");
}