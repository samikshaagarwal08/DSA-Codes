#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,a[]={5,8,7,3,4,2},s,t;
    s=sizeof(a)/sizeof(a[0]);
    printf("\narray is:\n");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
    for(i=1;i<s;i++)
    {
        for(j=0;j<s-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("\nSorted array:");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
}