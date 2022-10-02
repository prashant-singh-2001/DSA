#include <stdio.h>
#include <conio.h>

void main()
{
    int as[10];
    int freq[10];
    printf("\n\nName : Prashant Singh \n");
    printf("Roll Number : MCAN1CA22019\n\n");
    printf("**Frequency of Numbers **\n\n");

    //Input in array
    for (int i = 0; i < 10; i++)
    {
        printf("A[%d] : ",i);
        scanf("%d",&as[i]);
    }
    
    //Counting frequency and storing it in an array!
    for (int i = 0; i < 10; i++)
    {
        if (as[i] != -1)
        {
            freq[i] = 1;
            for (int j = i + 1; j < 10; j++)
            {
                if (as[i] == as[j])
                {
                    freq[i]++;
                    as[j] = -1;
                }
            }
        }
    }
    
    //Printing the frequencies
    printf("Frequencies of number : \n");
    for (int i = 0; i < 10; i++)
    {
        if (as[i] != -1)
            printf(" %-5d :: %5d\n", as[i], freq[i]);
    }
    
}