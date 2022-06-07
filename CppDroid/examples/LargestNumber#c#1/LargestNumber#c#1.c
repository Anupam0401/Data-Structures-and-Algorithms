/*
Summary: Finds largest number from array and its location
*/

#include <stdio.h>

int main()
{
	int array[100], maximum, size, c, location = 1;
	
	printf("Enter the number of elements in array\n");
	scanf("%d", &size);
	
	printf("Enter %d integers\n", size);
	
	for (c = 0; c < size; c++)
		scanf("%d", &array[c]);
	
	maximum = array[0];
	
	for (c = 1; c < size; c++)
	{
		if (array[c] > maximum)
		{
			maximum  = array[c];
			location = c+1;
		}
	}
	
	printf("Maximum element is present at location %d and it's value is %d.\n", location, maximum);
	return 0;
}

/*
Input: Enter the number of elements in array
5
Enter 5 integers
4
5
6
8
2

*/