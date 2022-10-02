#include <stdio.h>
#include <conio.h>

void main()
{
    int odd[9];
    int even[9] ;
    int nums[] = {1, 1, 1, 2, 3, 1, 3, 5, 4};
    int j = 0, k = 0;
    printf("\n\nName : Prashant Singh \n");
    printf("Roll Number : MCAN1CA22019\n\n");
    printf("** Separate Numbers in ODD and EVEN Arrays **\n\n");
    
    //Displaying Array
    printf("The array is : ");
    for (int i = 0; i < 9; i++)
    {
        printf("[%d] ",nums[i]);
    }
    

    //Separating numbers
    for (int i = 0; i <= 8; i++)
    {
        if (nums[i] % 2 == 0)
        {
            even[j] = nums[i];
            j++;
        }
        else
        {
            odd[k] = nums[i];
            k++;
        }
    }
    printf("\nThe even numbers are : %d", j);
    for (int i = 0; i < j; i++)
    {
        printf("\n %d", even[i]);
    }
    printf("\nOdds are : %d", k);
    for (int i = 0; i < k; i++)
    {
        printf("\n %d", odd[i]);
    }

    return;
}