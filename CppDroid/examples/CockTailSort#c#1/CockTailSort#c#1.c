/*
Summary: Cocktail sort is a variation of bubble sort that is both a stable sorting algorithm and a comparison sort. The algorithm differs from a bubble sort in that it sorts in both directions on each pass through the list. This sorting algorithm is only marginally more difficult to implement than a bubble sort, and solves the problem of turtles in bubble sorts.
The various names of cocktail sort are bidirectional bubble sort, cocktail shaker sort, shaker sort, ripple sort, shuffle sort, shuttle sort or happy hour sort.
Complexity - O(n^2)
*/

#include <stdio.h>
#define MAX 8
int main()
{
	int data[MAX];
	int i, j, n, c;
	printf("\nEnter the data\n");
	for (i = 0; i < MAX; i++)
	{
		scanf("%d", &data[i]);
	}
	n = MAX;    
	do
	{
/*Rightward pass will shift the largest element to its correct place at the end*/
		for (i = 0;  i < n - 1; i++)
		{
			if (data[i] > data[i + 1])
			{
				data[i] = data[i] + data[i + 1];
				data[i + 1] = data[i] - data[i + 1];
				data[i] = data[i] - data[i + 1];
			}
		}
		n = n - 1;
/* Leftward pass will shift the smallest element to its correct place at the beginning*/
		for (i= MAX - 1, c = 0; i >= c; i--)
		{
			if(data[i] < data[i - 1])
			{
				data[i] = data[i] + data[i - 1];
				data[i - 1] = data[i] - data[i - 1];
				data[i] = data[i] - data[i - 1];
			}
		}
		c = c + 1;
	} while (n != 0 && c != 0);
	printf("The sorted elements are:  ");
	for (i = 0; i < MAX; i++)
	{
		printf("%d\t", data[i]);
	}
	printf("\n");
}

/*
Input: Enter the data
9 6 2 12 11 9 3 7
*/