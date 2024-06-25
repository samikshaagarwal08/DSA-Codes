#include<stdio.h>
int main()
{
	int n1,n2,i,j,f=0;
	printf("write prime no. between an interval:\n");
	scanf("%d%d",&n1,&n2);
	printf("prime no. between %d and %d:\n",n1,n2);
	for(i=n1;i<=n2;i++)
	{
		f=0;
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
			{
				f=1;
				break;
			}
		}
		if(f==0 && i!=1)
			{
				 printf(" %d ",i);
			}
	}
	return 0;
}