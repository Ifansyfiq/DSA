//Fibbonaci sequence using recursion
#include <stdio.h>
#include <conio.h>

int fib(int);

int main()
{
   int num;
   printf("\nEnter number for fibonacci sequence: ");
   scanf("%d",&num);

   printf("\nFibonacci %d = %d",num,fib(num));
   getch();
   return 0;
}

int fib(int num)
{
   if (num==0||num==1) //stopping condition
   	return num;

	return (fib(num-1)+fib(num-2));
}
