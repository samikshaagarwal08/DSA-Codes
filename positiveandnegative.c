#include<stdio.h>
#include<conio.h>
void main()
{
    int a;
    printf("enter a no.");
    scanf("%d",&a);
    if(a>0)
        printf("positive no.");
    else if(a==0)
        printf("zero");
        else
            printf("negative no.");
    getch();
}