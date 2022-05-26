/*
Summary: Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. Each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
Complexity - O(n^2)
*/

#include <stdio.h>
#define MAX 10
void insertion_sort(int *);
void main()
{
	int a[MAX], i;
	clrscr();
	printf("enter 10 elements to be sorted:");
	for (i = 0;i < MAX;i++)
	{
		scanf("%d", &a[i]);
	}
	insertion_sort(a);
	printf("sorted elements:\n");
	for (i = 0;i < MAX; i++)
	{
		printf(" %d", a[i]);
	}
	getch();
}

/* sorts the input */
void insertion_sort(int * x)
{
	int temp, i, j;
	for (i = 1;i < MAX;i++)
	{
		temp = x[i];
		j = i - 1;
		while (temp < x[j] && j >= 0)
		{
			x[j + 1] = x[j];
			j = j - 1;
		}
		x[j + 1] = temp;
	}
}


/*
Input: enter elements to be sorted:8 2 4 9 3 6 1
*/