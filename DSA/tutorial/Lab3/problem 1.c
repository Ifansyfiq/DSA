#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct Record
{
    char name[50];
    char matrixId[10];
    char course[10];
    char title[50];
    char field[10];
    char supervisor[50];
};

int main(void)
{
    int i,j;
    struct Record record[2];

    system ("cls");

    for (i=0;i<2;i++)
    {
    printf("\nStudent's Name : ");
    scanf("%s",&record[i].name);

    printf("\nMatrix ID : ");
    scanf("%s",&record[i].matrixId);

    printf("\nCourse : ");
    scanf("%s",&record[i].course);

    printf("\nProject's Title : ");
    scanf("%s",&record[i].title);

    printf("\nField : ");
    scanf("%s",&record[i].field);

    printf("\nSupervisor : ");
    scanf("%s",&record[i].supervisor);
    printf("\n--------------------------------------------");
    }




    for (j=0;j<2;j++)
    {
    printf("\n");
    printf("\nStudent's Name : %s",record[j].name);
    printf("\nMatrix ID : %s",record[j].matrixId);
    printf("\nCourse : %s",record[j].course);
    printf("\nProject's Title : %s",record[j].title);
    printf("\nField : %s",record[j].field);
    printf("\nSupervisor : %s",record[j].supervisor);
    printf("\n--------------------------------------------");

    }



}



















