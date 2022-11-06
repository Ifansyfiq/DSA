//Tower of Hanoi
#include <stdio.h>
#include <conio.h>

int main()
{
	void move(int, char,char,char);
	int numDisks;
	printf("\nPlease enter number of disks: ");
	scanf(" %d", &numDisks);

	if(numDisks>0)
		move(numDisks , 'A','C','B');

   getch();
   return 0;
}

void move(int numDisks, char from, char destination, char intermediate)
{
   static int step = 0; //keep the contain of variable between calls
 	if (numDisks==1)
 	{
    printf("\nStep %d: Move disk 1 from needle %c to needle %c",++step,from,destination);
    return;
   }

 	else
	{
	move(numDisks-1, from, intermediate, destination);
	printf("\nStep %d: Move disk %d from needle %c to needle %c",++ step, numDisks,from,destination);
	move(numDisks-1,intermediate, destination , from);
 	}
}

