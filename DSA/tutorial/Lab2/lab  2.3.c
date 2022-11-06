#include <stdio.h>

int pattern(int);
int print(int);


int main()
{
   int n;
   printf("\n enter number of stars:");
   scanf("%d",&n);
   pattern(n);

   return 0;
}


int pattern(int n)
{
    int i;
    if(n==0)
    {
        return 1;
    }
    else
    {
        printf("\n");
        for (i=1;i<=n;i++)
        {
            printf("*");
        }
        return pattern(n-1);
    }
}


