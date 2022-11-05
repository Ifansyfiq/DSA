#include <stdio.h>
#include <time.h>

void heap_sort(long [], long);
void display(long [], long);
clock_t start, end;
double cpu_time_used;
int tot_comp,tot_step;

void main()
{
    int num=1, n = 5000;
    long array[30000];

    for(int i = 1; i <= 6; i++)
    {   srand(time(0));
        tot_comp=0,tot_step=0;
        for(int j=0; j<n; j++)
            array[j]=rand()%n;
        heap_sort(array, n);
        printf("\n\nSECTION : %d", i);
        printf("\nSIZE : %d", n);
        printf("\nTIME: %.4f seconds", cpu_time_used);
        printf("\nTOTAL COMPARE: %d", tot_comp);
        printf("\nTOTAL STEP: %d", tot_step);
        printf("\n============================");
        n+=5000;
    }
}

void heap_sort(long heap[], long no)
{
#include <stdio.h>

void main()
{
    int heap[10], no, i, j, c, root, temp, k;

    printf("\n Enter no of elements :");
    scanf("%d", &no);                         --------------- 1
    printf("\n Enter the element : ");    --------------- 1
    for (i = 0; i < no; i++)                  ----------------- n
       scanf("%d", &heap[i]);             ----------------- 1
    for (i = 1; i < no; i++)                  ----------------- n
    {
        //c = i;
        for (c = i; c > 0; c=root)           ----------------- logn.n because root=(c-1)/2
        {
            root = (c - 1) / 2;                ------------ 1.logn.n
            if (heap[root] < heap[c])   /* to create MAX heap array */  ------ 1.logn.n
            {
                temp = heap[root]; ------- 1.logn.n
                heap[root] = heap[c]; ------- 1.logn.n
                heap[c] = temp; ------- 1.logn.n
            }
        }
    }

}

