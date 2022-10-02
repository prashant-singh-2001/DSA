#include <stdio.h>
#include <conio.h>

int main()
{
     int a[10];
     printf("\n\nName : Prashant Singh \n");
     printf("Roll Number : MCAN1CA22019\n\n");
     printf("** Printing in Reverse **\n\n");

     // Storing the values of the array
     printf("Enter the numbers of the array : \n");
     for (int i = 0; i < 10; i++)
     {
          printf("Array[%d]: ",i);
          scanf("%d", &a[i]);
     }

     // Printing the values in reverse
     printf("\nAnd in reverse :");
     for (int i = 9; i >= 0; i--)
     {
          printf("\nArray[%d]: %d", i,a[i]);
     }
     return 0;
}