#include <stdio.h>
#include <time.h>

int shell_sort(long [], long);
void display(long [], long);
clock_t start, end;
double cpu_time_used;
int tot_comp,tot_step;

void main()
{
    int num=1, n = 5000;
    long array[30000];
    float elapseMsec;

    for(int i = 1; i <= 6; i++)
    {   srand(time(0));
        tot_comp=0,tot_step=0;
        for(int j=0; j<n; j++)
            array[j]=rand()%n;
        //start = clock();
        start = clock() * CLK_TCK;
        shell_sort(array, n);
       end = clock() * CLK_TCK;
        elapseMsec = end / 1000;
        cpu_time_used = elapseMsec / 1000;
        /*end = clock();
        cpu_time_used = (double)(end-start)/CLOCKS_PER_SEC;*/
        printf("\n\nSECTION : %d", i);
        printf("\nSIZE : %d", n);
        printf("\nTIME: %.4f seconds", cpu_time_used);
        printf("\nTOTAL COMPARE: %d", tot_comp);
        printf("\nTOTAL STEP: %d", tot_step);
        printf("\n============================");
        n+=5000;
    }
}

int shell_sort(long shell[], long no)
{
 for (int interval = no/2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < no; i += 1)
        {
            /* store a[i] to the variable temp and make the ith position empty */
            int temp = shell[i];
            int j;
            for (j = i; j >= interval && shell[j - interval] > temp; j -= interval)
            {
               shell[j] = shell[j - interval];
                tot_comp++;
            }
            // put temp (the original a[i]) in its correct position
            shell[j] = temp;
            tot_step++;
        }

    }
    return 0;
}
