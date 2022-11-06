/*Factorial (n) computation  using iteration*/

#include <stdio.h>
#include <conio.h>

int fact(int);//function prototypes

int main()
{

    int number,factNum;

    printf("\nEnter a positive number: ");
    scanf("%d",&number);
    factNum=fact(number);//call the function
    printf("\nFactorial number for %d\! = %d",number,factNum);

    getch();
    return 0;
}

/*Iterative factorial*/

int fact(int number)//function defination
{  int i,result = 1;

   for (i=number;i>1;i--)
	{
    result=result*i;
	}

	return result;
}
