#include <stdio.h>

int sum(int,int);

int main()
{
    int i,n,totalsum;

    printf("\n enter I value:");
    scanf("%d",&i);
    printf("\n enter N value:");
    scanf("%d",&n);
    totalsum=sum(i,n);

    printf("\n summation of i and n is : %d",totalsum);

    return 0;
}

int sum(int i,int n)
{
    int w,result=0;

    for (w=i;i<=n;i++)
    {
        result=result+i;
    }
    return result;
}


