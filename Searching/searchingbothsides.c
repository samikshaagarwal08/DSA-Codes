#include<stdio.h>
#include<stdlib.h>
#define size 10
int main()
{
    int i,n,s,a[size],f=0,x;
    x:
    printf("\nenter the size of array(max size %d):",size);
    scanf("%d",&s);
    if(s>size || s<1)
    {
        printf("invalid size");
        goto x;
    }
    printf("\nenter %d elements in array",s);
    for(i=0;i<s;i++)
        scanf("%d",&a[i]);
    printf("\nEnter an element to be searched:");
    scanf("%d",&n);
    for(i=0;i<s/2;i++)
    {
        if(a[i]==n)
            f=1;
        else if(a[s-1-i]==n)
            f=1;
    }
    if(f==0)
        printf("\nELEMENT NOT FOUND");
    else
        printf("\nELEMENT FOUND");
}