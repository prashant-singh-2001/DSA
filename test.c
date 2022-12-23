#include<stdio.h>
#include<conio.h>
#include<math.h>
void main(){
    int n=1;
    for (int i = 0; i < 200; i=pow(n++,2))
    {
        printf("%d\t",i);
    }
}