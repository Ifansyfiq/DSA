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

struct node *front, *rear,*thisptr, *newptr;

void main()
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

void enqueue()  // 1 mark
{
      newptr=(struct node *)malloc(sizeof (struct node)); // 1 mark

    printf("\nEnter an element: ");// 1 mark
   scanf("%d",&newptr->element);
   newptr->ptrnext=NULL; // 1 mark


	if (front==NULL) // 1 mark
	{	front=newptr; // 1 mark
		rear=newptr;	// 1 mark
	}

	else
	{
		rear->ptrnext=newptr; // 1 mark
		rear=newptr;	// 1 mark
	}

   list_node();
}

void dequeue()// 1 mark
{

	thisptr = front; // 1 mark


	if (front==NULL) // 1 mark
	{
		printf("\nEmpty list\n\n");// 1 mark
      return;
	}

	else
	{
	front=front->ptrnext; // 1 mark
	delete 	thisptr; // 1 mark
	}
   list_node();
}

void list_node()
{
	if (front==NULL) // 1 mark
	{
		printf("\nEmpty list\n\n");// 1 mark
		return;
	}

	thisptr=front; // 1 mark
	do
	{
		printf("\n\n%d",thisptr->element); // 1 mark
		printf("\n");
		thisptr=thisptr->ptrnext;
	}while(thisptr !=NULL); // 1 mark
}

