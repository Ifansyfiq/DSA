#include<stdio.h>
#include<stdlib.h>

	

struct subjects
{
    float marks;
};

struct examination_results
{
    char student_id[10];
    char sutdent_name[100];
    char  classroom[20];
    struct subjects BM;
    struct subjects BI;
    struct subjects Math;
    struct subjects Sains;
};


void display (struct examination_results data); // declare prototype before main function

float calculate_marks (struct examination_results data);

int main()
{
    struct examination_results myInfo;
    float total = 0;

    printf("ID: ");
    scanf("%s", &myInfo.student_id);
    printf("Name: ");
    scanf("%s", &myInfo.sutdent_name);
    printf("Classroom: ");
    scanf("%s", &myInfo.classroom);
    printf("Subject Mark for BM: ");
    scanf("%f", &myInfo.BM.marks);
    printf("Subject Mark for BI: ");
    scanf("%f", &myInfo.BI.marks);
    printf("Subject Mark for Math: ");
    scanf("%f", &myInfo.Math.marks);
    printf("Subject Mark for Sains: ");
    scanf("%f", &myInfo.Sains.marks);

    display (myInfo);
    total = calculate_marks (myInfo);
    printf("\nThe total marks is: %.2f", total);

    return 0;
}


void display (struct examination_results data)
{

    printf("\n\n==========Examination Results=============");
    printf("\nID: %s", data.student_id);
    printf("\nName: %s", data.sutdent_name);
    printf("\nClassroom: %s", data.classroom);
    printf("\nSubject Mark for BM: %.2f", data.BM.marks);
    printf("\nSubject Mark for BI: %.2f", data.BI.marks);
    printf("\nSubject Mark for Math: %.2f", data.Math.marks);
    printf("\nSubject Mark for Sains: %.2f", data.Sains.marks);
    printf("\n==========End of Examination Results==============");


}

float calculate_marks (struct examination_results data)
{

    float total = 0;

    total = data.BM.marks + data.BI.marks + data.Math.marks + data.Sains.marks;

    return total;

}








