#include<stdio.h>
#include<conio.h>
int main()
{
        int a,b;
        printf("enter a no.");
        scanf("%d%d",&a,&b);
        if(a>b)
            printf("%d is greater",a);
        else if(a==b)
            printf("both are equal");
        else
            printf("%d is greater",b);
        return 0;
} 