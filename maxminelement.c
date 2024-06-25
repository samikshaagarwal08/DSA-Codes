#include<stdio.h>
#define s 10
int main()
{
	int a[s],i,max,min;
	printf("Array is:\n");
	for(i=0;i<s;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=0;i<s;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
    printf("\n maximum number : %d",max);
	min=a[0];
	for(i=0;i<s;i++)
	{
		if(a[i]<min)
			min=a[i];
	}
	printf("\n minimum number : %d",min);
	return 0;
}