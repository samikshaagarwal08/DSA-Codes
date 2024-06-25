#include<stdio.h>
void swap(int *p,int *q)
{
    int t=*p;
    *p=*q;
    *q=t;
}
int partition(int *a,int lb,int ub)
{
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[lb],&a[end]);
    return end;
}
void quicksort(int *a,int lb,int ub)
{
    if(lb<ub)
    {
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
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
    quicksort(a,lb,ub);
    printf("\nSorted array:");
    for(i=0;i<s;i++)
        printf("%d ",a[i]);
}