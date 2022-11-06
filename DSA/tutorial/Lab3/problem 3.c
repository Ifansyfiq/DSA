#include <stdio.h>
#include <conio.h>

struct Student      //structure name
{
	char id[10];      // structure member
    char name[25];
	char classroom[50];
	struct Subject total;
}  ;

struct Subject
{
    int bm;
    int bi;
    int math;
    int sains;
    int total;
};

void display (struct Student); //prototypes
struct Student getStudentInfo();//prototypes

int main()
{
   struct Student stud;

   stud=getStudentInfo();

   display(stud);  //pass structure variable to function
   getch();
   return 0;
}

struct Student getStudentInfo()//function definition
{
    printf("\nBaby %d",i);
    printf("\nEnter baby name: ");
	scanf(" %[^\n]s",&newborn[i].name);
	printf("\nEnter baby gender: ");
	scanf(" %[^\n]s",&newborn[i].gender);

    return stud1;
}

void display(struct Student student)//function definition
{
	printf("\nstudent.name = %s",student.name);
	printf("\nstudent.id = %s",student.id);
	printf("\nstudent.age = %d",student.age);
}
