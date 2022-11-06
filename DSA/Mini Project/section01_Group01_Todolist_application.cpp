/*
Lecturer: Wan Muhammad Syahrir bin Wan Hussin
Title: To Do List Application

SECTION 1B
Muhammad Thaqiyuddin Bin Mizan CB20038
Muhammad Izzat Syamir Bin Azmi CB20100
Muhammad Adhwa Bin Mohd Salemi CB20053
Muhammad Irfan Syafiq Bin Mohd Bakhtiar CB20040
Muhammad Irfan Bin Ahmad Suhaimi CB20059
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct Student
{
    char name[50];
    char matric[10];
    int sem;
    int yearStudy;
    char category;
    char type[20];
};

struct Date
{
    int day;
    int month;
    int year;
};

struct Tag
{
    int priority;
};

struct ToDoList
{
    char todo[50];
    char desc[100];
    struct Date d;
    struct Tag t;
    struct ToDoList *ptrnext;
};

struct ToDoList *front, *rear, *thisptr, *newptr;

struct Student getDetail(); //returning structure
struct Student typeToDo(struct Student s); //returning and passing structure
void displayDetail(struct Student *s); //passing structure
void enqueue(); //insert at beginning
void dequeue(); //delete at beginning
void displayToDo();
void ToDoUpdate(); //update
void ToDoSearch(); //Linear search
void sortByDate(); //Bubble sort
void swapDate(struct ToDoList *a, struct ToDoList *b);
void sortByPriority(); //Bubble sort
void swapPriority(struct ToDoList *c, struct ToDoList *d);

int main()
{

    struct Student info;
        info=getDetail();
        info=typeToDo(info);
        displayDetail(info);

    char ch;
    int choice=TRUE;

    front=NULL;

	while(choice==TRUE)
	{
        printf("\n\nChoose One");
		printf("\nA. Add To-Do-List");
		printf("\nB. Delete To-Do-List");
		printf("\nC. Display To-Do-List");
		printf("\nD. Update To-Do List");
		printf("\nE. Search To-Do List");
		printf("\nF. Sort To-Do List by Date");
		printf("\nG. Sort To-Do List by priority");
		printf("\nH. Exit");
		printf("\n\nEnter choice: ");

		scanf(" %c",&ch);
		ch=toupper(ch);
		switch (ch)

		{
		case 'A': enqueue();
				  break;

		case 'B': dequeue();
				  break;

		case 'C': displayToDo();
				  break;

        case 'D': ToDoUpdate();
				  break;

        case 'E': ToDoSearch();
				  break;

        case 'F': sortByDate();
				  break;

        case 'G': sortByPriority();
				  break;

		case 'H': choice=FALSE;
				  break;

		default: printf("\nInvalid entry. Please select 'A','B','C','D'\n");
		}
	}
    getch();
	return 0;
}

struct Student getDetail()
{
    struct Student info;

    printf("\nFill in all the details");
    printf("\n\nName: ");
    scanf("%s", &info.name);
    printf("\nMatric ID: ");
    scanf("%s", &info.matric);
    printf("\nEnter semester of study: ");
    scanf("%d", &info.sem);
    printf("\nEnter year of study: ");
    scanf("%d", &info.yearStudy);
    printf("\nCategory: \nR-Reminder \nT-Task \nO-Others \n");
    scanf(" %c", &info.category);

    return info;
};

struct Student typeToDo(struct Student s)
{

    if(s.category=='R')
    {
        strcpy(s.type,"Reminder");
    }
    else if(s.category=='T')
    {
        strcpy(s.type,"Task");
    }
    else
    {
        strcpy(s.type,"Others");
    }


    return s;
}

void displayDetail(struct Student *s)
{
    
    
        printf("\n\nStudent details");
        printf("\nName: %s",s.name);
        printf("\nMatric ID: %s", s.matric);
        printf("\nSemester: %d", s.sem);
        printf("\nYear: %d", s.yearStudy);
        printf("\nCategory: %s", s.type);
    
}


void enqueue()
{
    newptr=(struct ToDoList *)malloc(sizeof(struct ToDoList));

    printf("\nEnter To-Do List: ");
    fscanf(stdin," ");
    fgets(newptr->todo,50,stdin);
    printf("\nEnter To-Do List Description: ");
    fgets(newptr->desc,100,stdin);
    printf("\nEnter date of To-Do List(day) (1-31): ");
    scanf("%d",&newptr->d.day);
    printf("\nEnter date of To-Do List(month) (1-12): ");
    scanf("%d",&newptr->d.month);
    printf("\nEnter date of To-Do List(year): ");
    scanf("%d",&newptr->d.year);
    printf("\nEnter priority (1 - most important, 5 - Least important): ");
    scanf("%d",&newptr->t.priority);

    newptr->ptrnext=NULL;

	if(front==NULL)
	{
	    front=newptr;
	    rear=newptr;
	}

	else
	{
		rear->ptrnext=newptr;
		rear=newptr;
	}

   displayToDo();
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

   displayToDo();
}

void displayToDo()
{
	if(front==NULL)
    {
        printf("\nEmpty list\n\n");
        return;
	}

	thisptr=front;

	do
   {
        printf("\n\nStudent To-Do List");
		printf("\nTo-Do List: %s", thisptr->todo);
		printf("To-Do List Description: %s", thisptr->desc);
		printf("Date: %d / %d / %d", thisptr->d.day,thisptr->d.month,thisptr->d.year);
		printf("\nPriority (1 - most important, 5 - Least important): %d", thisptr->t.priority);
		printf("\n");

		thisptr=thisptr->ptrnext;
	} while(thisptr !=(struct ToDoList *)NULL);
}

void ToDoUpdate()
{
    int num;
    char oriTitle[50], newTitle[50], newDesc[100];
    int newDay, newMonth, newYear;


    printf("\n\nEnter To-Do List title to be updated: ");
    fscanf(stdin," ");
    fgets(oriTitle,50,stdin);

    thisptr=front;

    while(thisptr != NULL)
    {
        num = strcmp(thisptr->todo, oriTitle);

        if(num == 0)
        {
            printf("\nEnter new To-Do List title: ");
            fscanf(stdin," ");
            fgets(newTitle,50,stdin);
            printf("\nEnter new To-Do List description: ");
            fgets(newDesc,100,stdin);
            printf("\nEnter new date of To-Do List(day) (1-31): ");
            scanf("%d",&newDay);
            printf("\nEnter new date of To-Do List(month) (1-12): ");
            scanf("%d",&newMonth);
            printf("\nEnter new date of To-Do List(year): ");
            scanf("%d",&newYear);

            strcpy(thisptr->todo, newTitle);
            strcpy(thisptr->desc, newDesc);
            thisptr->d.day = newDay;
            thisptr->d.month = newMonth;
            thisptr->d.year = newYear;

        }
        else
        {
            thisptr = thisptr->ptrnext; //point to next node
        }
    }

    displayToDo();
}

void ToDoSearch()
{

    char searchTitle[50];
    int num;

    if (front==NULL) //head node is NULL (empty)
    {
        printf("\n\nTo-Do List is empty\n");//no To-Do added yet
    }

    else
    {
        printf("\nEnter To-Do List Title to search:");
        fscanf(stdin," ");
        fgets(searchTitle,50,stdin);

        thisptr=front;

        while(thisptr->ptrnext!=NULL)
        {

        num = strcmp(thisptr->todo,searchTitle);

        if (num == 0) //found
            {
                printf("\n%s To-Do List is found!",thisptr->todo);

                printf("\n\nTo-Do List Details");
                printf("\nTo-Do List Title : %s",thisptr->todo);
                printf("To-Do List Description: %s",thisptr->desc);
                printf("To-Do List Date\t : %d / %d / %d",thisptr->d.day,thisptr->d.month,thisptr->d.year);
                printf("\n");

                return;
            }
        else
            {

            thisptr=thisptr->ptrnext; //if not found, point to next node(title)
            }

        }


       num = strcmp(thisptr->todo,searchTitle);

            if (num == 0) //found
            {
                printf("\n%s found!",thisptr->todo);

                printf("\n\nTo-Do List Details");
                printf("\nTo-Do List Title : %s",thisptr->todo);
                printf("To-Do List Description: %s",thisptr->desc);
                printf("To-Do List Date : %d / %d / %d",thisptr->d.day,thisptr->d.month,thisptr->d.year);
                printf("\n");


            }
            else
            {
                printf("\nSorry,no match found");
            }

    }

}

void sortByDate()
{

    int swap;
    struct ToDoList *ptrDate = NULL;

    if (front == NULL)
        return;

    do
    {
        swap = 0;
        newptr = front;

        while (newptr->ptrnext != ptrDate)
        {
            if(newptr->d.year > newptr->ptrnext->d.year)
            {
                swapDate(newptr, newptr->ptrnext);
                swap =1;
            }
            else if(newptr->d.year == newptr->ptrnext->d.year && newptr->d.month > newptr->ptrnext->d.month)
            {
                swapDate(newptr, newptr->ptrnext);
                swap =1;
            }


             else if (newptr->d.year == newptr->ptrnext->d.year && newptr->d.month == newptr->ptrnext->d.month && newptr->d.day > newptr->ptrnext->d.day)
            {
                swapDate(newptr, newptr->ptrnext);
                swap = 1;
            }
            newptr = newptr->ptrnext;
        }
        ptrDate = newptr;
    }
    while (swap);

    displayToDo();
}


void swapDate(struct ToDoList *a, struct ToDoList *b)
{

    int tempDay, tempMonth, tempYear, tempPriority;
    char TempTitle[50], tempDesc[100];

     if (a->d.year > b->d.year)
    {
        tempDay = a->d.day;
        a->d.day = b->d.day;
        b->d.day= tempDay;

        tempMonth = a->d.month;
        a->d.month = b->d.month;
        b->d.month = tempMonth;

        tempYear = a->d.year;
        a->d.year = b->d.year;
        b->d.year = tempYear;

        tempPriority = a->t.priority;
        a->t.priority = b->t.priority;
        b->t.priority = tempPriority;

        strcpy(TempTitle,a->todo);
        strcpy(a->todo,b->todo);
        strcpy(b->todo,TempTitle);

        strcpy(tempDesc,a->desc);
        strcpy(a->desc,b->desc);
        strcpy(b->desc,tempDesc);

    }
    else if(a->d.year == b->d.year && a->d.month > b-> d.month)
    {
        tempDay = a->d.day;
        a->d.day = b->d.day;
        b->d.day= tempDay;

        tempMonth = a->d.month;
        a->d.month = b->d.month;
        b->d.month = tempMonth;

        tempYear = a->d.year;
        a->d.year = b->d.year;
        b->d.year = tempYear;

        tempPriority = a->t.priority;
        a->t.priority = b->t.priority;
        b->t.priority = tempPriority;

        strcpy(TempTitle,a->todo);
        strcpy(a->todo,b->todo);
        strcpy(b->todo,TempTitle);

        strcpy(tempDesc,a->desc);
        strcpy(a->desc,b->desc);
        strcpy(b->desc,tempDesc);

    }
    else if(a->d.year == b->d.year && a->d.month == b-> d.month && a->d.day > b->d.day)
    {
        tempDay = a->d.day;
        a->d.day = b->d.day;
        b->d.day= tempDay;

        tempMonth = a->d.month;
        a->d.month = b->d.month;
        b->d.month = tempMonth;

        tempYear = a->d.year;
        a->d.year = b->d.year;
        b->d.year = tempYear;

        tempPriority = a->t.priority;
        a->t.priority = b->t.priority;
        b->t.priority = tempPriority;

        strcpy(TempTitle,a->todo);
        strcpy(a->todo,b->todo);
        strcpy(b->todo,TempTitle);

        strcpy(tempDesc,a->desc);
        strcpy(a->desc,b->desc);
        strcpy(b->desc,tempDesc);
    }


}

void sortByPriority()
{
    int swap;
    struct Event *ptrPriority = NULL;

    if (front == NULL)
        return;

    do
    {
        swap = 0;
        newptr = front;

        while (newptr->ptrnext != ptrPriority)
        {
            if (newptr->t.priority > newptr->ptrnext->t.priority)
            {
                swapPriority(newptr, newptr->ptrnext);
                swap = 1;
            }
            newptr = newptr->ptrnext;
        }
        ptrPriority = newptr;
    }
    while (swap);

    displayToDo();
}

void swapPriority(struct ToDoList *c, struct ToDoList *d)
{
    int tempDay, tempMonth, tempYear, tempPriority;
    char TempTitle[50], tempDesc[100];

    tempDay = c->d.day;
    c->d.day = d->d.day;
    d->d.day = tempDay;

    tempMonth = c->d.month;
    c->d.month = d->d.month;
    d->d.month = tempMonth;

    tempYear = c->d.year;
    c->d.year = d->d.year;
    d->d.year = tempYear;

    tempPriority = c->t.priority;
    c->t.priority = d->t.priority;
    d->t.priority = tempPriority;

    strcpy(TempTitle,c->todo);
    strcpy(c->todo,d->todo);
    strcpy(d->todo,TempTitle);

    strcpy(tempDesc,c->desc);
    strcpy(c->desc,d->desc);
    strcpy(d->desc,tempDesc);

}


