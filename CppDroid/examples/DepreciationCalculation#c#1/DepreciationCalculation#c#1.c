/*
Summary: Compute the yearly depreciation of the value of an item, given by Depreciation = (PURCHASE VALUE - SALVAGE VALUE) / YEAR OF SERVICE 
*/

#include<conio.h>
#include<stdio.h>
void main()
{
	float sv,pv,dep;
	int yos;
	clrscr();

	printf("Enter the purchase value :- ");
	scanf("%f",&pv);

	printf("Enter the year of service :- ");
	scanf("%d",&yos);

	printf("Enter the value of depreation :- ");
	scanf("%f",&dep);


	sv = pv - (dep * yos);
	printf("\n The salvage value equal to :- %f",sv);

	getch();
}

/*
Input: Enter the value of purchase value :- 800
Enter the year of service :- 200
Enter the value of depreation :- 2
*/