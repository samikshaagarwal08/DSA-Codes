#include<stdio.h>
int main()
{
    int i,j,min,a[]={5,8,7,3,4,2},s,t;
    s=sizeof(a)/sizeof(a[0]);
    printf("\nArray is:");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
    for(i=0;i<s-1;i++)
    {
        min=i;
        j=i+1;
        while(j<s)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            j++;
        }
        if(i!=min)
        {
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
    printf("\nSorted array:");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
}