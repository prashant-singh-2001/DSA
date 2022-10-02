#include <stdio.h>
#include <conio.h>

void main()
{
    int array[50];
    int n, flag = 1;
    int a = 0;
    int i = 0;
    printf("Enter number elements to be stored in array (Less than 50!) : \n");
    scanf("%d", &n);
    for (; i < n; i++)
    {
        printf("\nEnter %d value : ", i + 1);
        scanf("%d", &array[i]);
    }
    while (flag == 1)
    {
        printf("\nChoose your Poison : \n");
        printf("Insert in the array : 1\n");
        printf("Delete from array : 2\n");
        printf("Search in the array : 3\n");
        printf("View array : 4\n");
        printf("Any other to exit!\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
        {
            int index, data, j ;
            n = n + 1;
            j=n;
            printf("\nEnter the index of new value : ");
            scanf("%d", &index);

            printf("\nEnter the new value : ");
            scanf("%d", &data);

            while (j >= index)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[index] = data;
            break;
        }
        case 2:
        {
            int k, index, data;
            printf("Enter the index of data to delete : ");
            scanf("%d", &index);
            data = array[index];
            k = index;
            while (k < n)
            {
                array[k]=array[k+1];
                k++;
            }
            n = n - 1;
            printf("The deleted value is : %d\n", data);
            break;
        }
        case 3:
        {
            int data;
            int i = 0;
            printf("Enter the value to search : ");
            scanf("%d", &data);
            for (; i < n; i++)
            {
                if (array[i] == data)
                    break;
                else if (i == n - 1)
                    i = -1;
            }
            if (i != -1)
                printf("The data is at index : %d\n", i);
            else
                printf("The data was not present in the array!\n");
            break;
        }
        case 4:
        {
            printf("\n");
            int i=0;
            for (; i < n; i++)
            {
                printf("\nArray %d : %d ",i+1,array[i]);
            }
            break;
            
        }
        default:
            flag=a;
            break;
        }
    }
}