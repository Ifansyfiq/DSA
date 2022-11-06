//Generate random number
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int range, max,min,num_rand;

   FILE *input; /*declare a file */
	input = fopen("data.txt", "w"); /*create the file*/

   printf("\nHow many random number you want to generate?:");
   scanf("%d",&num_rand);
   printf("\nEnter the maximum value for your random number:");
   scanf("%d",&max);
   printf("\nEnter the minimum value for your random number:");
   scanf("%d",&min);

   srand(time(NULL));
   range = (max-min)+1;/*plus 1 because the max value can still be generated*/


   for (int i = 0; i<num_rand;i++)
   {fprintf(input,"%d\n", rand()%range+min);//plus min to shift min & max value
   }

   printf("\ndata.txt has been sucessfully created");

	fclose(input);/*close the file*/



	getch();
	return 0;
}



