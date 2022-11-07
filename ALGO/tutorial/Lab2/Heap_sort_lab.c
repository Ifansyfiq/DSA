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
    int  i, j, c, root, temp, k;

    clock_t start = clock();
    for (i = 1; i < no; i++)
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
    for (j = no - 1; j >= 0; j--)
    {
        temp = heap[0];
        /* swap max element with rightmost leaf element */
        heap[0] = heap[j];
        heap[j] = temp;

        root = 0;
        do
        {
            c = 2 * root + 1;    /* left node of root element */
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            /* again rearrange to max heap array */
            if (heap[root]<heap[c] && c < j)
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
                //tot_comp++;
            }
            root = c;
            //tot_step++;
        } while (c < j);

    }
    clock_t end = clock();
    cpu_time_used = (double)(end-start)/CLOCKS_PER_SEC;

}

