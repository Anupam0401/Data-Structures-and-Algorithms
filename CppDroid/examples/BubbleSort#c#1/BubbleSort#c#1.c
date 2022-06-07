/*
Summary: Bubble sort is a simple sorting algorithm that works by repeatedly stepping through the list to be sorted, comparing each pair of adjacent items and swapping them if they are in the wrong order.
Complexity - O(n^2)
*/

#include <stdio.h>
#define MAXSIZE 10

void main()
{
	int array[MAXSIZE];
	int i, j, num, temp;

	printf("Enter the value of num \n");
	scanf("%d", &num);

	printf("Enter the elements one by one \n");
	for (i = 0; i < num; i++)
	{
		scanf("%d", &array[i]);
	}

   /*   Bubble sorting begins */
	for (i = 0; i < num; i++)
	{
		for (j = 0; j < (num - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	
	printf("Sorted array is...\n");
	for (i = 0; i < num; i++)
	{
		printf("%d\n", array[i]);
	}
	getch();
}

/*
Input: Enter the value of num
6
Enter the elements one by one
23
45
67
89
12
34
*/