#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0


void enqueue();
void dequeue();
void list_node();


struct node
{
	int element;
	struct node *ptrnext;
};

struct node *front, *rear, *thisptr, *newptr;

int main()
{
	char ch;
	int choice=TRUE;

	front=NULL;
	while(choice==TRUE)

	{
		printf("\n\n[-----------Queue Menu-----------]");
		printf("\nA - Enqueue queue");
		printf("\nB - Dequeue queue");
		printf("\nD - Display queue content");
		printf("\nX - Exit\n");
		printf("\nEnter choice: ");
		scanf(" %c",&ch);
		ch=toupper(ch);
		switch(ch)
		{
		case 'A':enqueue();break;
		case 'B':dequeue();break;
		case 'D':list_node();break;
		case 'X': choice=FALSE; break;

		default: printf("\nOnly one of the above");
		}
	}
   getch();
}

void enqueue()
{
	newptr=(struct node *)malloc(sizeof (struct node));

	printf("\nEnter an element: ");
    scanf("%d",&newptr->element);
    newptr->ptrnext=NULL;


	if (front==NULL)
	{	front=newptr;
		rear=newptr;
	}

	else
	{
		rear->ptrnext=newptr;
		rear=newptr;
	}

   list_node();
}

void dequeue()
{

	thisptr = front;


	if (front==NULL)
	{
      printf("\nEmpty list\n\n");
      return;
	}

	else
	{
	front=front->ptrnext;
	free(thisptr);
	}
   list_node();
}

void list_node()
{
	if (front==NULL)
	{
		printf("\nEmpty list\n\n");
		return;
	}

	thisptr=front;
	do
	{
		printf("\n\n%d",thisptr->element);
		printf("\n");
		thisptr=thisptr->ptrnext;
	}while(thisptr !=NULL);
}
