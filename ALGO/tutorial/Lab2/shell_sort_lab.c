#include <stdio.h>
#include <time.h>

void shell_sort(long [], long);
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
        shell_sort(array, n);
        end = clock();
        cpu_time_used = (double)(end-start)/CLOCKS_PER_SEC;
        printf("\n\nSECTION : %d", i);
        printf("\nSIZE : %d", n);
        printf("\nTIME: %.4f seconds", cpu_time_used);
//            printf("\n%.4f", cpu_time_used);
        printf("\nTOTAL COMPARE: %d", tot_comp);
        printf("\nTOTAL STEP: %d", tot_step);
        printf("\n============================");
        n+=5000;
    }
}

void shell_sort(long heap[], long no)
{
 for (int interval = no/2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < no; i += 1)
        {
            /* store a[i] to the variable temp and make the ith position empty */
            int temp = heap[i];
            int j;
            for (j = i; j >= interval && heap[j - interval] > temp; j -= interval)
                heap[j] = heap[j - interval];

            // put temp (the original a[i]) in its correct position
            heap[j] = temp;
        }
    }
}
