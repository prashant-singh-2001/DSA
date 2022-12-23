#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 15

int BS(int *arr,int l,int r,int t){
    int m=(l+r)/2;
    if(arr[m]==t)
        return m;
    else if( l==r)
        return -1;
    else if(arr[m]>t)
        r=m-1;
    else 
        l=m+1;
    BS(arr,l,r,t);
}

void main(){
    int arr[MAX];
    int l=0;
    int r=MAX;
    int t=0;
    printf("\n\nName : Prashant Singh \n");
    printf("Roll Number : MCAN1CA22019\n\n");
    printf("** Recursive Binary Search (On Random Numbers) **\n\n");

    for(int i=0;i<MAX;i++){arr[i]=rand()%100;}
    for (int i = 0; i < (MAX - 1); i++)
    {
        for (int j = 0; j < (MAX - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Enter the number (0-99) to search : ");
    scanf("%d",&t);
    
    int index=BS(arr,l,r,t);
    
    if(index!=-1)
        printf("The item was found at: %d Index",index);
    else
        printf("The item was not in the list.");
}
