#include<stdio.h>
int main()
{
    int a[]={2,4,6,8,10},i,mid,lb=0,ub,s,t;
    s=sizeof(a)/sizeof(a[0]);
    printf("\nArray is:");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
    printf("\nenter the no. to be searched:");
    scanf("%d",&t);
    lb=0,ub=s-1;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        if(a[mid]==t)
        {
            printf("\nELEMENT FOUND");
            break;
        }
        else if(a[mid]<t)
            lb=mid+1;
        else
            ub=mid-1;
    }
    if(lb>ub)
        printf("\nELEMENT NOT FOUND");
}