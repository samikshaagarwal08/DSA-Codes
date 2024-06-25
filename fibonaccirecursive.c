#include<stdio.h>
int fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fib(n-1)+fib(n-2);
}
void main()
{
    int i,n;
    printf("\nEnter the number of elements in series:");
    scanf("%d",&n);
    for(i=0;i<10;i++)
    {
        printf("%d ",fib(i));
    }
}