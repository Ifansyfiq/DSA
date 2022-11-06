// Program to illustrates the searching in a linked list

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void new_number();
void list_number();
void search_number();

struct number
{
	int number;
	struct number *ptrnext;
};

struct number *headptr, *newptr, *currentptr, *previousptr;  //pointer that can point to a node

void main()
{
	char ch;
	int choice=TRUE;

	headptr=(struct number *)NULL;
	while(choice==TRUE)

	{
		printf("\n\ne - Enter a number");
		printf("\nl - List all numbers");
      printf("\nd - Search a number");
		printf("\nx - Exit\n");
		printf("\nEnter choice: ");
		scanf(" %c",&ch);
		switch(ch)
		{
		case 'e':new_number();break;
		case 'l':list_number();break;
      case 'd':search_number();break;
		case 'x': choice=FALSE; break;

		default: printf("\nEnter only one from the above");
		}
	}
   getch();
}

void new_number()
{
  newptr=(struct number *)malloc(sizeof (struct number)); // pointer to a new
  						//	memory allocation

if (headptr==(struct number *)NULL)//node is empty?
{      headptr=newptr; //first pointer point to first node
       newptr->ptrnext=(struct number *)NULL; //first node pointer point to null
 }

	else
	{
      newptr->ptrnext=headptr;// new node pointer point to previous first node
      headptr=newptr; // head point to new node,new node become first node

	}

	printf("\nEnter a number: ");
	scanf("%d",&newptr->number);

}

void list_number()
{
	if (headptr==(struct number*)NULL) //empty list
	{
		printf("\nEmpty list");
		return;
	}

	currentptr=headptr;
	do
	{
		printf("\n\n%d",currentptr->number);
		printf("\n");
		currentptr=currentptr->ptrnext; //point to next node
	}while(currentptr !=(struct number *)NULL);
}

void search_number()
{           int keyfield;

	if (headptr==(struct number *)NULL)//node is empty?
	  	{
      	printf("\n\nThe list is empty!!!\n");//the list is empty
      }

	else
	{
            printf("\nEnter key value for linear sequential search: ");
           scanf("%d",&keyfield);

   	currentptr=headptr;

	while(currentptr ->ptrnext!=(struct number *)NULL)
	{

          	if (currentptr->number == keyfield) //found the location
             	{
                 printf("\nKey match found !");
                 return;
          		}
            else
           {
               previousptr=currentptr;//save the previous current address
	currentptr=currentptr->ptrnext; //point to next node
          	}

         }

         if (currentptr->number == keyfield)
         	{
            printf("\nKey match found !");
            }
         else

          	printf("\nSorry, no match found ");


		}

}

