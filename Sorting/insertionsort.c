#include<stdio.h>
int main()
{
    int i,j,key,s,t,a[]={5,8,7,3,4,2};
    s=sizeof(a)/sizeof(a[0]);
    printf("\nArray is:");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
    for(i=1;i<s;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("\nSorted array:");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
}