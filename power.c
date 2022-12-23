#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

long powee(int n, int m)
{
    return m == 0 ? 1 : (m == 1 ? n : (n * powee(n, m - 1)));
}
int main()
{
    int n = 0, m = 0;
    printf("\n\n Name : Prashant Singh \n");
    printf("Roll Number: MCAN1CA22019\n\n");
    printf("** Recursive funtion for exponentials **\n\n");

    printf("Enter the base : ");
    scanf("%d", &n);
    printf("Enter the exponential : ");
    scanf("%d", &m);

    printf("The result of %d to the power of %d is : %ld",n,m,powee(n,m));
    return 0;
}
