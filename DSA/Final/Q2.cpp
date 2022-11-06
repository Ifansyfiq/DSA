#include <stdio.h>
#include <conio.h>
#define maxsize 10

void quickSort(int [],int,int);
int partition(int [],int,int);
void swap(int [],int,int);

int main()
{

	int i, num_elements, totalDeaths[maxsize];

	printf("\nHow many number you want to enter: ");
	scanf("%d",&num_elements);

	for(i=0; i<num_elements; i++)
	{
		printf("\nEnter number: ");
		scanf("%d",&totalDeaths[i]);
	}

	quickSort(totalDeaths,0,num_elements-1);

	printf("\nSorted list for selection sort: ");
	for(i=0; i<num_elements; i++)
		printf(" %d",totalDeaths[i]);

   getch();
}


void quickSort(int totalDeaths[],int first,int last)
{
	int pivotLocation;

	if(first<last)
	{
		pivotLocation=partition(totalDeaths,first,last);
        quickSort(totalDeaths,first,pivotLocation-1);
		quickSort(totalDeaths,pivotLocation+1,last);
	}

}

int partition(int totalDeaths[],int first,int last)
{
	int pivot,index,smallIndex;

	pivot = totalDeaths[last];
	smallIndex=first;

	for(index=first+1;index<=last;index++)
	 {	if(totalDeaths[index]<pivot)
		{
			smallIndex++;
			swap(totalDeaths,smallIndex,index);
		}
    }
	swap(totalDeaths,first,smallIndex);

	return smallIndex;
}


void swap(int totalDeaths[],int first,int second)
{
	int temp;
	temp=totalDeaths[first];
	totalDeaths[first]=totalDeaths[second];
	totalDeaths[second]=temp;
}
