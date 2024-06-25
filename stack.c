#include<stdio.h>
#include<stdlib.h>
#define size 100
int stk[size];
int top=-1;
void push(int data)
{
    if(top==size-1)
    {
        printf("\nstack is full");
        exit(0);
    }
    else
        stk[++top]=data;
}
void pop()
{
    if(top==-1)
    {
        printf("\nstack not defined");
        exit(0);
    }
    else
    {
        printf("%d is deleted",stk[top]);
        top--;
    }
}
void display()
{
    int i;
    for(i=0;i<=top;i++)
        printf("%d ",stk[i]);
}
void main()
{
    int data,ch;
    while(1)
    {
        printf("\nEnter\n1--add\n2--remove\n3--display\n0--exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter data");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
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