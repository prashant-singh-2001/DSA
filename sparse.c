#include <stdio.h>
#include <conio.h>

void main()
{
    int a[3][3];
    int count = 0;
    int k = (3 * 3) / 2;
    printf("\nName : Prashant Singh \n");
    printf("Roll Number : MCAN1CA22019\n\n");
    printf("** Sparse Matrix **\n\n");

    // Getting the values of matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter the value for a[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf(" \n\n--> Matrix <-- \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%3d ", a[i][j]);
        }

        printf("\n");
    }
    printf("------------\n");

    // Calculating the number of zeroes
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == 0)
            {
                count++;
            }
        }
    }

    // Deciding whether the matrix is sparse or not!
    if (count > k)
        printf("Given matrix is sparse Matrix ! ");
    else
        printf("Given matrix is not sparse MAtrix !");
}