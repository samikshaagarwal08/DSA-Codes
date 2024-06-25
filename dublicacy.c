#include <stdio.h>
int main()
{
    int a[] = {2, 2, 8, 9, 4, 3, 2, 1, 5, 4, 5, 3, 2, 2, 5, 7, 1, 2};
    int n = sizeof(a) / sizeof(a[0]), k = 0;
    int b[n];

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
    k = 0;
    b[k++]=a[0];
    int c[n],m=0;
    for (int i = 0; i < n; i++)
    {
        int f=1;
        for (int j = 0; j < k; j++)
        {
            if (a[i] == b[j])
            {
                f=0;
            }

        }
        if (f)
        {
            b[k++]=a[i];
        }
               
        
    }
    for (int i = 0; i < k; i++)
    {
        int count=0;;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == b[i])
            {
                count++;
            }

        }
            c[m++]=count;
        
        
               
        
    }
    printf("Array with no duplicates:\n");
    for (int i = 0; i < k; i++)
    {
        printf(" %d ", b[i]);
    }
    printf("\n");
    printf("Frequency of corresponding element:\n");
    for (int i = 0; i < k; i++)
    {
        printf(" %d ", c[i]);
    }
}