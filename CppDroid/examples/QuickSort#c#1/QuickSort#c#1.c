/*
Summary: Quicksort is a very efficient sorting algorithm.It has two phases:
-the partition phase and
-the sort phase. 
Most of the work is done in the partition phase - it works out where to divide the work. The sort phase simply sorts the two smaller problems that are generated in the partition phase. 
Complexity: O(n·log n)
*/

#include <stdio.h>
void quicksort (int [], int, int);
int main()
{
	int list[50];
	int size, i;
	clrscr();
	printf("Enter the number of elements: ");
	scanf("%d", &size); 
	printf("Enter the elements to be sorted:\n");
	for (i = 0; i < size; i++)
	{
		scanf("%d", &list[i]);
	} 
	quicksort(list, 0, size - 1);
	printf("After applying quick sort\n");
	for (i = 0; i < size; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");  
	getch();
	return 0;
}
void quicksort(int list[], int low, int high)
{
	int pivot, i, j, temp;
	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j) 
		{
			while (list[i] <= list[pivot] && i <= high)
			{
				i++;
			}
			while (list[j] > list[pivot] && j >= low)
			{
				j--;
			}
			if (i < j)
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}

		temp = list[j];
		list[j] = list[pivot];
		list[pivot] = temp;
		quicksort(list, low, j - 1);
		quicksort(list, j + 1, high);
	}
}


/*
Input: Enter the number of elements: 6
Enter the elements to be sorted:
67
45
24
98
12
38
*/