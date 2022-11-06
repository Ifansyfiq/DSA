#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void new_number();
void list_number();

struct Water
{
	char state[20];
	char river[20];
	int wqi;
	char category;

	struct Water *ptrnext; 
};

struct Water *headptr, *newptr, *currentptr;

int main()
{
	char ch;
	int choice=TRUE;

	headptr=NULL;
	while(choice==TRUE)

	{
		printf("\n\ne - Enter a data");
		printf("\nl - List all data");
		printf("\nx - Exit\n");
		printf("\nEnter choice: ");
		scanf(" %c",&ch);
		switch(ch)
		{
		case 'e':new_number();break;
		case 'l':list_number();break;
		case 'x': choice=FALSE; break;

		default: printf("\nEnter only one from the above");
		}
	}
 return 0;
}

void new_number()
{
  newptr=(struct Water *)malloc(sizeof(struct Water)); 															

  printf("\nEnter a state: ");
  scanf("%s",&newptr->state);
  printf("\nEnter a river: ");
  scanf("%s",&newptr->river);
  printf("\nEnter a water quality index (WQI): ");
  scanf("%d",&newptr->wqi);

  if (headptr==NULL)
  {headptr=newptr; 
   newptr->ptrnext=NULL; 
  }

  else
   {
    currentptr=headptr;

   while(currentptr->ptrnext !=NULL)
   {
    currentptr=currentptr->ptrnext;
   }

    currentptr->ptrnext=newptr; 
    newptr->ptrnext=NULL; 

   }

}

void list_number()
{
	if (headptr==NULL)
	{
		printf("\nEmpty list");
		return;
	}

	currentptr=headptr;

		printf("\nstate\tRiver\tWQI\tCategory");
	do
   {
   		
   		if (currentptr->wqi<=59)
   		{
   			   currentptr->category='P';			   
			   printf("\n%s\t%s\t%d\t%c\t",currentptr->state,currentptr->river,currentptr->wqi,	currentptr->category);
		}
		else if (currentptr->wqi>=60&&currentptr->wqi<=80)
		{
			currentptr->category='sp';
			printf("\n%s\t%s\t%d\t%c\t",currentptr->state,currentptr->river,currentptr->wqi,	currentptr->category);
		}
		else
		{
			currentptr->category='c';	
			printf("\n%s\t%s\t%d\t%c\t",currentptr->state,currentptr->river,currentptr->wqi,	currentptr->category);
		}
		
		currentptr=currentptr->ptrnext; 
	} while(currentptr !=NULL);
}









