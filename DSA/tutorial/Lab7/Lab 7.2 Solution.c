//Binary Search
#include <stdio.h>
#include <conio.h>
#define maxsize 10

void binary_search(int [],int, int);

void main()
{
	int x,y,temp;
	int i, num_elements, data[maxsize];
	int keyfield;


	/*Read in a value for number of elements */

	printf("\nEnter list size: ");
	scanf("%d",&num_elements);

	/*Read in the list of number */
	for(x=0; x<num_elements; x++)
	{
		printf("\nEnter number: ");
		scanf("%d",&data[x]);
	}



	/*Sort list in ascending order*/
	for(x=0; x<num_elements;x++)
		for(y=x+1; y<num_elements; y++)
			if(data[x]>data[y])
			{
				temp=data[x];
				data[x]=data[y];
				data[y]=temp;
			}

   /*Display (sorted) the list of numbers entered earlier by user */
	printf("\nSorted list of element entered: ");
	for(i=0; i<num_elements; i++)
		printf(" %d",data[i]);

	/*Read in the key value for binary search */
	printf("\n\nEnter key value for binary search: ");
	scanf("%d",&keyfield);

	/*Called the binary search function */
	binary_search(data, num_elements, keyfield);



   getch();
}


void binary_search(int data[],int size, int keyfield)
{
	int first=0;
	int last=size - 1;
	int mid;
 	int n=0;

	bool found=false;

	while(first<=last && !found)
	{
	  mid=(first+last)/2;
	   printf("\nValue for mid: %d",mid);
                 n++;
		if(data[mid]==keyfield)
			found=true;
		else
			if(data[mid]>keyfield)
				last=mid - 1;
			else
				first=mid + 1;
	}

	if (found)

	{printf("\n\nKey match found in data[%d]",mid);
               printf("\nNumber of comparison is %d",n);

	return;
	}

	else

	{printf("\n\nSorry, no match found !");
   	printf("\nNumber of comparison is %d",n);
		return;
	}



}

