/*
Summary: Calculates compund interest
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	float p,t,r;
	float i,compound,a;
	clrscr();

	printf("enter principal:\t");
	scanf("%d",&p);

	printf("enter rate of interest:\t");
	scanf("%d",&r);

	printf("enter time in years:\t");
	scanf("%d",&t);

	if((p<1)||(t<1)||(r<1))
		printf("invalid");
	else
	{
		a=(float)p*(pow(1+r/100.0,t));
		compound=a-p;
		printf("the compound interest is rs.%.2f",compound);
	}
	getch();
}

/*
Input: enter principal: 100
enter rate of interest: 10
enter time in years: 1
*/