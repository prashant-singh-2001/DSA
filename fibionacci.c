#include <stdio.h>
#include <conio.h>

void fib(int n)
{
    int a = 0;
    int b = 1;
    int c;
    printf("%d\n", a);
    for (int i = 0; i <= n; i++)
    {
        printf("%d\n", b);
        c = a;
        a = b;
        b = a + c;
    }
    return;
}
void main()
{
    int n;
    printf("ENter the number of elements of fibonacci series : ");
    scanf("%d", &n);
    fib(n);
    getch();
    return;
}