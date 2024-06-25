#include<stdio.h>
void main()
{
    int a=8,b=9,c=3,d=2,e,f=0;
    if(a==b && a==c && a==d)
        printf("all are equal");
    if(a>b)
    {
        if(a>=c)
        {
            if(a>=d)
                e=a;
            else
                e=d;
        }
        else
        {
            if(c>=d)
                e=c;
            else
                e=d;
        }
        f=1;    
    }
    else
    {
        if(b>=c)
        {
            if(b>=d)
                e=b;
            else
                e=d;
        }
        else
        {
            if(c>=d)
                e=c;
            else
                e=d;
        } 
        f=1; 
    }
    if(f==1)
        printf("\n%d is greatest",e);
}