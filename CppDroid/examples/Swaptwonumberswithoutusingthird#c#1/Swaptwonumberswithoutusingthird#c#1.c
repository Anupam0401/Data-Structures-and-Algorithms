/*
Summary: Program swaps two number without using temporary variable
*/

#include <stdio.h>
void main()
{
	int a,b;

	printf("Enter a and b");
	scanf("%d",a);
	scanf("%d",b);

	printf("Before Swapping a=%d,b=%d"a,b);
	a=a+b;
	b=a-b;
	a=a-b;

	printf("After Swapping a=%d,b=%d"a,b);
}

/*
Input: Enter a and b
10 20
*/