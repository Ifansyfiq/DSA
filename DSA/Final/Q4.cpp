#include <stdio.h>
#include <conio.h>

#define maxsize 10

void quick_sort(int [],int,int);

int main()
{

    int i, death, data[maxsize];

    printf("\nEnter Total Death: ");
    scanf("%d",&death);

    for(i=0; i<death; i++)
    {
        printf("\nEnter number: ");
        scanf("%d",&data[i]);
    }

    quick_sort(data, 0,death-1);

    printf("\nSorted list for Total Death: ");
    for(i=9; i>=0; i--)
        printf(" %d",data[i]);

      getch();
      return 0;
}


void quick_sort(int data[],int bottom,int top)
{
    int left, right,temp, pivot,flag;
    if(top>bottom)
    {
        pivot=data[top];
        right=top;
        left=bottom-1;
        do
        {
            flag=1;
            while(data[++left]<pivot);
            while(data[--right]>pivot);
            if(left<right)
            {
                temp=data[left];
                data[left]=data[right];
                data[right]=temp;
            }

            else
            {
                break;
            }

        }while(flag>0);
        temp=data[left];
        data[left]=data[top];
        data[top]=temp;

        quick_sort(data,bottom,left-1);
        quick_sort(data,left+1,top);
    }

}
