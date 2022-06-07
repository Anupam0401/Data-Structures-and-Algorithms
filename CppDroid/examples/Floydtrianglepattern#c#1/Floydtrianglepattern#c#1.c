/*
Summary: Number of rows of Floyd's triangle to print is entered by the user. First four rows of Floyd's triangle are as follows :-
1
2 3
4 5 6
7 8 9 10
It's clear that in Floyd's triangle nth row contains n numbers.
*/

#include <stdio.h>

int main()
{
	int n, i,  c, a = 1;
	
	printf("Enter the number of rows of Floyd's triangle to print\n");
	scanf("%d", &n);
	printf("Floyd's triangle\n");
	for (i = 1; i <= n; i++)
	{
		for (c = 1; c <= i; c++)
		{
			printf("%d ",a);
			a++;
		}
		printf("\n");
	}
	
	return 0;
}

/*
Input: Enter the number of rows of Floyd's triangle to print
4
*/