#include<stdio.h>
#include<stdlib.h>
#define size 100
int q[size];
int f=-1;
int r=-1;
void enqueue(int data)
{
    if(r==-1)
    {
        r=f=0;
        q[r]=data;
    }
    else if((r+1)%size==f)
    {
        printf("\nQueue is full");
    }
    else
    {
        r=(r+1)%size;
        q[r]=data;
    }
}
void dequeue()
{
    if(f==-1)
        printf("\nqueue is empty");
    else if(f==r)
    {
        printf("\n%d deleted",q[f]);
        f=r=-1;
    }
    else
    {
        printf("\n%d deleted",q[f]);
        f=(f+1)%size;
    }
}
void display()
{
    if(f==-1)
        printf("\nqueue is empty");
    else
    {
        int i=f;
        printf("\nqueue is:");
        while(i!=r)
        {
            printf("%d ",q[i]);
            i=(i+1)%size;
        }
        printf("%d ",q[r]);
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