/*
Summary: Prints triangle using *
*/

#include<stdio.h>

main()
{
	int n, c, k = 2, j;

	printf("Enter number of rows\n");
	scanf("%d",&n);

	for ( j = 1 ; j <= n ; j++ ){
		for ( c = 1 ; c <= 2*n-k ; c++)
			printf(" ");		
		k = k + 2;

		for ( c = 1 ; c <= j ; c++)
			printf("*   ");
		printf("\n");
	} 

	getch();
	return 0;
}



/*
Input: Enter number of rows
4
*/