#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
        start = clock();
        heap_sort(array, n);
         end = clock();
    cpu_time_used = (double)(end-start)/CLOCKS_PER_SEC;
        printf("\n\nSECTION : %d", i);
        printf("\nSIZE : %d", n);
        printf("\nTIME: %.4f seconds", cpu_time_used);
        printf("\nTOTAL COMPARE: %d", tot_comp);
        printf("\nTOTAL STEP: %d", tot_step);
        printf("\n============================");
        n+=5000;
    }
    return 0;
}

void heap_sort(long heap[], long n)
{
    int  i, c, root, temp, k;


    for (i = 1; i < n; i++)
    {

        for (c = i; c > 0; c=root)
        {
            root = (c - 1) / 2;
            if (heap[root] < heap[c])   /* to create MAX heap array */
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;

            }

        }
    }
    for (k = n - 1; k >= 0; k--)
    {
        temp = heap[0];
        /* swap max element with rightmost leaf element */
        heap[0] = heap[k];
        heap[k] = temp;

        root = 0;
        do
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((heap[c] < heap[c + 1]) && c < k-1)
            {
               c++;
            }
            /* again rearrange to max heap array */
            if (heap[root]<heap[c] && c < k)
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
                tot_comp++;
            }
            root = c;
            tot_step++;
        } while (c < k);
    }

}

