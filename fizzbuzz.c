#include<stdio.h>
#include<conio.h>

void fb(int n)
    {
        int i=0;
        while(i<n)
            {
                int j=i+1;
                if(j%3==0 && j%5==0)
                    printf("\n FIZZBUZZ");
                else if(j%3==0)
                    printf("\n FIZZ");
                else if(j%5==0)
                    printf("\n BUZZ");
                else
                    printf("\n%d",j);
            i++;
            }
            return;
    }
    int main()
    {
        int n;
        printf("Enter a number : ");
        scanf("%d",&n);
        fb(n);
        return 0;
    }