/*
Summary: Sum of numbers between 100 and 200 which are divisible by 7
*/

#include<stdio.h>
#include<conio.h>

void main()
{
	int i,sum = 0;
	clrscr();

	for(i = 100;i <= 200 ; i++)
	{
		if (i % 7 == 0)
			sum = sum + i;
	}
	printf("Sum of all no between 100 and 200 ");
	printf("which is divisible by 7 is :: %d",sum);
	getch();
}

/*
Input: No input
*/