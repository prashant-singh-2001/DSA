#include <stdio.h>
#include <conio.h>
int checkValid(int *, int);
void palindrome(int *, int);
int main()
{
    int num;
    printf("Enter the number");
    scanf("%d", &num);
    int arr[9];
    int i = 0;
    while (num != 0)
    {
        arr[i] = num % 10;
        num /= 10;
        i++;
    }
    int size = i;
    if (checkValid(arr, size))
    {
        palindrome(arr, size);
    }
    else
        printf("The number is un-readable");

    return 0;
}
int checkValid(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        switch (arr[i])
        {
        case 2:
            return 0;
            break;
        case 3:
            return 0;
            break;
        case 4:
            return 0;
            break;
        case 5:
            return 0;
            break;
        case 7:
            return 0;
            break;
        }
    }
    return 1;
}
void palindrome(int *arr, int size)
{
    // size = size - 1;
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == arr[size - i])
        {
            continue;
        }
        else if ((arr[i] == 6 & arr[size - i] == 9) || (arr[i] == 9 & arr[size - i] == 6))
        {
            continue;
        }
        else
            flag = 1;
    }
    if (flag == 1)
    {
        printf("Number is not mirror palindrome!");
    }
    else
        printf("Number is mirror palindorme!");
}