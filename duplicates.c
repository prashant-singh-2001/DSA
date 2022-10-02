#include <stdio.h>
#include <conio.h>
void main()
{
    int n = 0;
    int a[10];
    printf("\n\nName : Prashant Singh \n");
    printf("Roll Number : MCAN1CA22019\n\n");
    printf("** Duplicates  **\n\n");
    
    //Input in array
    for (int i = 0; i < 10; i++)
    {
        printf("A[%d] : ",i);
        scanf("%d",&a[i]);
    }
    
    //Counting total duplicates
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 13; j++)
        {
            if (a[i] == -1)
                continue;
            if (a[i] == a[j])
            {
                n = n + 1;
                a[j] = -1;
            }
        }
    }

    printf("Total Duplicates are : %2d", n);
}