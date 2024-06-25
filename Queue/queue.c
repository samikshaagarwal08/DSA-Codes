#include<stdio.h>
#include<stdlib.h>
#define size 100
int q[size];
int f=-1;
int r=-1;
void enqueue(int data)
{
    if(r==size-1)
    {
        printf("\nqueue is full");
        exit(0);
    }
    else if(r==-1)
    {
        f=r=0;
        q[r]=data;
    }
    else
    {
        r++;
        q[r]=data;
    }
}
void dequeue()
{
    if(f==-1)
    {
        printf("\nqueue is empty");
        exit(0);
    }
    else if(f==r)         //last element
    {
        printf("\n%d deleted",q[f]);
        f=r=-1;
    }
    else
        printf("%d deleted",q[f++]);
}
void display()
{
    int i;
    if(r==-1)
    {
        printf("\nqueue is empty");
    }
    else
    {
        for(i=f;i<=r;i++)
            printf("%d ",q[i]);
    }
}
void main()
{
    int data,ch;
    while(1)
    {
        printf("\nEnter\n1--add\n2--delete\n3--display\n0--exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter data:");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                exit(0);
            default:
                break;
        }
    }
}