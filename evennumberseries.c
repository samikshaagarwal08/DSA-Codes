#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
int main()
{
    int i,n,j;
    printf("enter the upper limit");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            int textcolor(BLUE);
            _cprintf(" * ");
        }
            printf("\n");
    }    
    return 0;    
}