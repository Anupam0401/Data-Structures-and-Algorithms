/*
Summary: Print sum of series
1 + 1/2 + 1/3 + 1/4 + ... + 1/N. 
*/

#include<stdio.h>
#include<conio.h>
void main()
{
	double n,sum=0,i;
	clrscr();

	printf("\n Please Give The Value of N:  ");
	scanf("%lf",&n);

	for(i=1;i<=n;i++)
	{
		sum = sum + (1/i);
		if(i==1)
			printf("\n 1 +");
		else if(i==n)
		    printf(" (1/%d)  ",i);
		else
			printf(" (1/%d) + ",i);
	}

	printf("\n\n THE SUM OF THIS SERIES IS %.2lf",sum);
	getch();
}

/*
Input:  Please Give The Value of N:  5
*/