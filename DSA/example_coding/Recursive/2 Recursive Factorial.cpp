//Factorial (n) computation using recursion

#include <stdio.h>
#include <conio.h>

int fact(int);//function prototypes

int main()
{

int number,factNum;

printf("\nEnter positive number: ");
scanf("%d",&number);
factNum=fact(number);
printf("\nFactorial number for %d\! = %d",number,factNum);
getch();
return 0;

}

/*Recursive factorial*/

int fact(int number)
{
	if(number==0)  //stopping condition
     {
		return 1;
     }
	else
     {
	   return (number*fact(number-1));
     }
}
