#include<stdio.h>
#include<conio.h>
int main()
{
    int i,n;
    printf("enter the upper limit of odd no. series");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
         if(i%2)
         printf("%d ",i);
    }
    return 0;
}