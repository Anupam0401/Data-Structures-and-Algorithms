/*
Summary: Check whether a number is armstrong or not. A number is armstrong if the sum of cubes of individual digits of a number is equal to the number itself. For example 371 is an armstrong number as 27 + 343 + 1 = 371.
*/

#include <stdio.h>

int main()
{
	int number, sum = 0, temp, remainder;
	
	printf("Enter an integer\n");
	scanf("%d",&number);
	
	temp = number;
	
	while( temp != 0 )
	{
		remainder = temp%10;
		sum = sum + remainder*remainder*remainder;
		temp = temp/10;
	}
	
	if ( number == sum )
		printf("Entered number is an armstrong number.\n");
	else
		printf("Entered number is not an armstrong number.\n");
	
	return 0;
}

/*
Input: Enter a number to check if it is an armstrong number
371
*/