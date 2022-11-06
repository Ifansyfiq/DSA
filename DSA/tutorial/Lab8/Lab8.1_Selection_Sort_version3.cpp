#include <stdio.h>
#include <conio.h>
#include <time.h>

//#define maxsize 10

void selection_sort(int [],int);
clock_t BeginTimer();
clock_t EndTimer(clock_t);

int compare=0,move =0;

int main()
{
    double begin;
    float elapTicks;
    float elapMilli, elapSeconds, elapMinutes;



	int num_elements = 0, data[100000],i;

	/*Read in values from data.txt*/

   FILE *input; /*declare a file */
	input = fopen("data.txt", "r"); /*read the file*/

   printf("The random numbers in data.txt are:\n\n");

   while (fscanf(input,"%d", &data[num_elements])!= EOF) /* read from file*/
	{
		printf("%d\t",data[num_elements]); /*display to the screen */
   	num_elements++;
	}

    printf ("Timer set to: %.2f\n", begin); // print the initialised timer (0)
    begin = BeginTimer();

	/*Called the selection sort function */
	selection_sort(data, num_elements);




    // variable definitions on to calculate time taken
    elapTicks = EndTimer(begin);    // stop the timer, and calculete the time taken
    elapMilli = elapTicks/1000;     // milliseconds from Begin to End
    elapSeconds = elapMilli/1000;   // seconds from Begin to End
    elapMinutes = elapSeconds/60;   // minutes from Begin to End


	/*Display the sorted list of number */
printf("\nSorted list for selection sort: \n");
	for(i=0; i<num_elements; i++)
	printf(" %d",data[i]);

   printf("\n\n\nNumber of data compare is %d",compare);
   printf("\nNumber of data move is %d\n",move);

   printf ("\n\nMilliseconds passed: %.2f\n", elapMilli);
   printf ("Seconds passed: %.2f\n", elapSeconds);
   printf ("Minutes passed: %.2f\n", elapMinutes);


   //getch();
   return 0;
}


void selection_sort(int data[],int num_elements)
{
	int smallest;
	int a, b, temp;

	for(a=0;a<num_elements; a++)
	{
		smallest = a;
		for(b=a+1;b<num_elements; b++)
		  {	if(data [b]<data[smallest])
			  {	smallest=b; }
         compare++;

        }
			temp=data[a];
         move++;
			data[a]=data[smallest];
         move++;
			data[smallest]=temp;
         move++;
	}

}


clock_t BeginTimer()
{
    //timer declaration
    clock_t Begin; //initialize Begin

    Begin = clock() * CLK_TCK; //start the timer

    return Begin;
}
clock_t EndTimer(clock_t begin)
{
    clock_t End;
    End = clock() * CLK_TCK;   //stop the timer
    return End;
}
