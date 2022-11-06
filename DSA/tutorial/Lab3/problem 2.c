
#include <stdio.h>
#include <conio.h>

struct parent
{
    char name[30];
	int age;
};

struct Birthday
{
    int day;
    int month;
    int year;
};

struct baby
{
	char name[30];
	char gender[10];
    struct Birthday record;
	struct parent father;
	struct parent mother;
};

int main()
{
    int i,j;
    struct baby newborn[2];

    system ("cls");
    for (i=0;i<2;i++)
    {
    printf("\nBaby %d",i);
    printf("\nEnter baby name: ");
	scanf(" %[^\n]s",&newborn[i].name);
	printf("\nEnter baby gender: ");
	scanf(" %[^\n]s",&newborn[i].gender);

	printf("\nDay birthday :");
	scanf("%d",&newborn[i].record.day);
    printf("\nMonth birthday :");
	scanf("%d",&newborn[i].record.month);
    printf("\nYear birthday :");
	scanf("%d",&newborn[i].record.year);

	printf("\nEnter father name: ");
	scanf(" %[^\n]s",&newborn[i].father.name);
	printf("\nEnter father age: ");
	scanf(" %d",&newborn[i].father.age);

	printf("\nEnter mother name: ");
	scanf(" %[^\n]s",&newborn[i].mother.name);
	printf("\nEnter mother age: ");
	scanf(" %d",&newborn[i].mother.age);

	printf("\n");
	printf("\n-------------------------------------------------");
    }



    printf("\n\n\t\tNEW BORN BABY IN KUANTAN HOSPITAL");

    system ("cls");
    for (j=0;j<2;j++)
    {

    printf("\n\nBaby's Name: %s",newborn[j].name);
	printf("\nGender: %s",newborn[j].gender);

	printf("\nBirthday: %d %d %d",newborn[j].record.day,newborn[j].record.month,newborn[j].record.year);

	printf("\nFather name: %s",newborn[j].father.name);
	printf("\nFather age: %d",newborn[j].father.age);
    printf("\nMother name: %s",newborn[j].mother.name);
	printf("\nMother age: %d",newborn[j].mother.age);

   printf("\n\n\n---------------------------------");
    }



   getch();
   return 0;
}






