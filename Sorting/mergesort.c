#include<stdio.h>
int merge(int *a,int lb,int mid,int ub)
{
    int i=lb,j=mid+1,k=lb,b[100];
    while(i<=mid && j<=ub)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=ub)
        b[k++]=a[j++];
    for(i=0;i<=ub;i++)
        a[i]=b[i];
}
int mergesort(int *a,int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
int main()
{
    int a[]={5,8,7,4,3,2},lb=0,ub,s,i;
    s=sizeof(a)/sizeof(a[0]);
    ub=s-1;
    printf("\nArray is:");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
    mergesort(a,lb,ub);
    printf("\nSorted array:");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
}