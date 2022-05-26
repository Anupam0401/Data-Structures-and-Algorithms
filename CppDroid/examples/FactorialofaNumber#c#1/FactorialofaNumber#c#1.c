/*
Summary: Factorial is represented using '!', so five factorial will be written as (5!),n factorial as (n!).
n! = n*(n-1)*(n-2)*(n-3)...3.2.1 and zero factorial is defined as one i.e. 0! = 1.
*/

#include <stdio.h>

int main()
{
	int c, n, fact = 1;
	
	printf("Enter a number to calculate it's factorial\n");
	scanf("%d", &n);
	
	for (c = 1; c <= n; c++)
		fact = fact * c;
	
	printf("Factorial of %d = %d\n", n, fact);
	
	return 0;
}

/*
Input: Enter a number to calculate it's factorial
6
*/