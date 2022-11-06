#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAXSEMESTER 30

struct Semester{
    int creditHours;
    float gpa;
};

struct Student{
    char* name[30];
    char* matricID[30];
    float cgpa;
    int semesterNumber;
    struct Semester semester[MAXSEMESTER];
    struct Student *link;
};

struct Student *top=NULL;

void push();
void pop();
void list();
void bubbleSort();
void swap(struct Student *a, struct Student *b);
void calculateCGPA(struct Student *temp);
void linearSearch();

int main(void){

    char opt;
    do
    {
        printf("\n<<<STUDENT GPA & CGPA CALCULATION SYSTEM>>>");
        printf("\nA - Add Student"); //PUSH
        printf("\nU - Undo Add Student"); //POP
        printf("\nC - Calculate All Student CGPA");//RECURSION
        printf("\nL - List All Student");
        printf("\nK - Sort Student Ascending CGPA");//BUBBLE SORT
        printf("\nS - Search Student"); //LINEAR SEQUENTIAL SEARCH
        printf("\nX - Exit");
        printf("\n\nEnter choice: ");
        scanf(" %c",&opt);

        switch (opt)
        {
        case 'A':
            printf("\n<<ADD STUDENT>>");
            push();
            break;
        case 'U':
            printf("\n<<UNDO ADD STUDENT>>");
            pop();
            break;
        case 'C':
            printf("\n<<CALCULATE ALL STUDENT CGPA>>");
            calculateCGPA(top);
            break;
        case 'L':
            printf("\n<<LIST ALL STUDENT>>");
            list();
            break;
        case 'K':
            printf("\n<<SORT STUDENT ASCENDING CGPA>>");
            bubbleSort();
            break;
        case 'S':
            printf("\n<<SEARCH STUDENT>>");
            linearSearch();
            break;
        case 'X':
            printf("\n<<THANK YOU>>\n");
            break;
        default:
            break;
        }
    } while (opt!='X');
}

void push(){
    struct Student *temp = (struct Student*)malloc(sizeof(struct Student*));
    printf("\nEnter Name: ");
    scanf("%s",&temp->name);
    printf("\nEnter Matric ID:");
    scanf("%s",&temp->matricID);
    printf("\nEnter number of semester: ");
    scanf("%d",&temp->semesterNumber);

    for (int j = 0; j < temp->semesterNumber; j++)
    {
        printf("\nEnter semester %d credit hours: ",(j+1));
        scanf("%d",&temp->semester[j].creditHours);
        printf("\nEnter semester %d GPA: ",(j+1));
        scanf("%f",&temp->semester[j].gpa);
    }

    temp->link = top;
    top = temp;
}

void pop(){
    struct Student *temp;

    if (top==NULL)
    {
        return;
    }

    temp = top;
    top = top->link;
    free(temp);
}

void list(){
    struct Student *temp=top;

    if (top==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        while (temp!=NULL)
        {
            printf("\nName\t\t: %s",temp->name);
            printf("\nMatric ID\t: %s",temp->matricID);
            printf("\nSemester Number : %d",temp->semesterNumber);
            printf("\nCGPA\t\t: %.2f",temp->cgpa);
            printf("\n");
            temp = temp->link;
        }
    }
}

void bubbleSort(){
    int swapped;
    struct Student *firstptr;
    struct Student *secondptr = NULL;

    /* Checking for empty list */
    if (top == NULL)
        return;

    do
    {
        swapped = FALSE;
        firstptr = top;

        while (firstptr->link != secondptr)
        {
            if (firstptr->cgpa > firstptr->link->cgpa)
            {
                swap(firstptr, firstptr->link);
                swapped = TRUE;
            }
            firstptr = firstptr->link;
        }
        secondptr = firstptr;
    }
    while (swapped==TRUE);
    list();
}


void swap(struct Student *a, struct Student *b){
    char nameTemp[30];
    char matricIDTemp[10];
    float cgpaTemp;
    int semesterNumberTemp;
    struct Semester semesterTemp[MAXSEMESTER];

    strcpy(nameTemp,a->name);
    strcpy(matricIDTemp,a->matricID);
    cgpaTemp = a->cgpa;
    semesterNumberTemp = a->semesterNumber;
    for (int i = 0; i < a->semesterNumber; i++)
    {
        semesterTemp[i].creditHours = a->semester->creditHours;
        semesterTemp[i].gpa = a->semester->gpa;
    }

    strcpy(a->name,b->name);
    strcpy(a->matricID,b->matricID);
    a->cgpa = b->cgpa;
    a->semesterNumber = b->semesterNumber;
    for (int i = 0; i < b->semesterNumber; i++)
    {
        a->semester->creditHours = b->semester->creditHours;
        a->semester->gpa = b->semester->gpa;
    }

    strcpy(b->name,nameTemp);
    strcpy(b->matricID,matricIDTemp);
    b->cgpa = cgpaTemp;
    b->semesterNumber = semesterNumberTemp;
    for (int i = 0; i < semesterNumberTemp; i++)
    {
        b->semester->creditHours = semesterTemp->creditHours;
        b->semester->gpa = semesterTemp->gpa;
    }
}

void calculateCGPA(struct Student *temp){
    float weightAverageGPA=0;
    int totalCreditHours=0;
    if (temp==NULL)
    {
        return;
    }
    else
    {
        for (int i = 0; i < temp->semesterNumber; i++)
        {
            totalCreditHours = totalCreditHours + temp->semester[i].creditHours;
            weightAverageGPA = weightAverageGPA + (temp->semester[i].creditHours) * (temp->semester[i].gpa);
        }
        temp->cgpa = weightAverageGPA / (float) totalCreditHours;
        calculateCGPA(temp->link);
    }
}

void linearSearch()
{
    struct Student *temp=top;
    char searchKeyword[10];

	printf("\nMatric ID to search:");
    scanf("%s",&searchKeyword);

    while (temp!=NULL)
    {
        if (strcmp(searchKeyword,temp->matricID));
        {
            printf("\n%s Found!",searchKeyword);
            printf("\nName\t\t: %s",temp->name);
            printf("\nMatric ID\t: %s",temp->matricID);
            printf("\nSemester Number : %d",temp->semesterNumber);
            printf("\nCGPA\t\t: %.2f",temp->cgpa);
            printf("\n");
            return;
        }
        temp=temp->link;
    }

	printf("\nSorry, %s not found",searchKeyword);
	return;
}
