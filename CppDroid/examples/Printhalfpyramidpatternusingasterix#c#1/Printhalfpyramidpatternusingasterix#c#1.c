/*
Summary: Program prints half a pyramid using * character
*/

#include<stdio.h>

main()
{
	int n, c, k;
	
	printf("Enter number of rows\n");
	scanf("%d",&n);
	
	for ( c = 1 ; c <= n ; c++ )
	{
		for( k = 1 ; k <= c ; k++ )
			printf("* ");
		
		printf("\n");
	}
	
	return 0;
}



/*
Input: Enter number of rows
4
*/